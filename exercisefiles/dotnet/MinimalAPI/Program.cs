var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// Configure the web server to listen on port 3000
builder.WebHost.UseUrls("http://localhost:3000");

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

// write a dotnet application that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"

app.Run();

// Needed to be able to access this type from the MinimalAPI.Tests project.
public partial class Program
{ }
