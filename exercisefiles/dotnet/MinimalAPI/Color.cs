public class Color
{
    [JsonPropertyName("name")]
    public required string Name { get; set; }

    [JsonPropertyName("category")]
    public required string Category { get; set; }

    [JsonPropertyName("type")]
    public required string Type { get; set; }

    [JsonPropertyName("code")]
    public required ColorCode Code { get; set; }
}

public class ColorCode
{
    [JsonPropertyName("rgba")]
    public required int[] RGBA { get; set; }

    [JsonPropertyName("hex")]
    public required string  HEX { get; set; }
}