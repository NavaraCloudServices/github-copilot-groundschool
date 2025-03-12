namespace IntegrationTests;

public class IntegrationTests : IClassFixture<TestWebApplicationFactory<Program>>
{
    private readonly HttpClient _client;

    public IntegrationTests(TestWebApplicationFactory<Program> factory)
    {
        _client = factory.CreateClient();
    }

    [Fact]
    public async Task Get_ReturnsHelloWorld()
    {
        // Arrange

        // Act

        var response = await _client.GetAsync("/hello");

        // Assert
        response.EnsureSuccessStatusCode();
        var content = await response.Content.ReadAsStringAsync();
        Assert.Equal("name not passed", content.Trim('"'));
    }
}
