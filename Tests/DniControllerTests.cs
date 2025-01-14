using Microsoft.AspNetCore.Mvc;
using github_copilot_hackathon.Controllers;
using Xunit;

namespace github_copilot_hackathon.Tests
{
    public class DniControllerTests
    {
        private readonly DniController _controller;

        public DniControllerTests()
        {
            _controller = new DniController();
        }

        [Theory]
        [InlineData("98765432M", "valid")]
        [InlineData("2424242H", "invalid")]
        public void ValidateSpanishDni_ReturnsExpectedResult(string dni, string expectedResult)
        {
            // Act
            var result = _controller.ValidateSpanishDni(dni) as OkObjectResult;

            // Assert
            Assert.NotNull(result);
            Assert.Equal(expectedResult, result.Value);
        }
    }
}
