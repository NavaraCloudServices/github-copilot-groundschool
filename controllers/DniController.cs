using Microsoft.AspNetCore.Mvc;

namespace github_copilot_hackathon.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class DniController : ControllerBase
    {
        private static readonly string DNI_LETTERS = "TRWAGMYFPDXBNJZSQVHLCKE";

        [HttpGet("validatespanishdni")]
        public IActionResult ValidateSpanishDni([FromQuery] string dni)
        {
            if (string.IsNullOrEmpty(dni) || dni.Length < 2)
                return BadRequest("Invalid DNI format");

            string number = dni.Substring(0, dni.Length - 1);
            char providedLetter = char.ToUpper(dni[dni.Length - 1]);

            if (!int.TryParse(number, out int dniNumber))
                return BadRequest("Invalid DNI number format");

            int index = dniNumber % 23;
            char calculatedLetter = DNI_LETTERS[index];

            return Ok(calculatedLetter == providedLetter ? "valid" : "invalid");
        }
    }
}
