# Goal

The goal is to create a Minimal WebAPI using .NET 8.0 with the help of GitHub Copilot.
Follow the instructions below and try to use GitHub Copilot as much as possible.
Try different things and see what GitHub Copilot can do for you, like generating a Dockerfile or a class, add comments, etc.

> Make sure GitHub Copilot is configured and enabled for the current language, just check the status bar on the bottom right corner of VS Code.

## Exercises

The `dotnet` folder contains the `MinimalAPI.sln` solution, with 2 projects:

- `MinimalAPI` is a minimal WebAPI project created using `dotnet new webapi -minimal`
- `MinimalAPI.Tests` is a minimal xUnit project created using `dotnet new xunit`

To run the tests, open a terminal in the `dotnet` folder and run:

```bash
dotnet test
```

To run the app, open a terminal in the `dotnet` folder and run:

**Windows environments**

```bash
dotnet run --project .\MinimalAPI\MinimalAPI.csproj
```

## Exercise 1: Introduction

- Inside `MinimalAPI\Program.cs` add a new Hello World endpoint at `/` that returns a `Hello World!` string. You can test the Copilot inline feature by pressing `ctrl + i`. Then write in the text box the desired behaviour.
- Run `dotnet test`
- If test pass you should see something like this:
  ```bash
  Microsoft (R) Test Execution Command Line Tool Version 17.6.0 (x64)
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Starting test execution, please wait...
  A total of 1 test files matched the specified pattern.

  Passed!  - Failed:     0, Passed:     1, Skipped:     0, Total:     1, Duration: < 1 ms - MinimalAPI.Tests.dll
  ```


## Exercise 2: Inline suggestions

>The goal of this exercise is using GitHub Copilot Inline suggestions feature to extend the HTTP server endpoints. 

GitHub Copilot offers coding suggestions as you type. For example, type this function header in a JavaScript file:
```javascript
function calculateDaysBetweenDates(begin, end) {
```
GitHub Copilot will automatically suggest the rest of the function. To accept the suggestion, press `Tab`. 

You can also describe something you want to do using natural language within a comment, and Copilot will suggest the code to accomplish your goal. For example, type this comment in a JavaScript file:

```JavaScript
// write a function to
// find all images without alternate text
// and give them a red border
```
GitHub Copilot will automatically suggest code. To accept the suggestion, press `Tab`.

Click [here](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot#getting-code-suggestions-2) for more information on Copilot code suggestions

You will be implementing the following additional features:
- [ ] DaysBetweenDates
- [ ] ValidatePhoneNumber
- [ ] ValidateSpanishDNI

---

### Implement the following:

Inside `MinimalAPI\Program.cs` add the following endpoints using the help of Copilot:

- **/DaysBetweenDates**:

  - Calculate days between two dates
  - receive by query string two parameters `date1` and `date2`, and calculate the days between those two dates.

> **_NOTE:_** Use above information inside the Copilot inline feature in the `Program.cs` file. Press enter and wait for Copilot to suggest you the code.

- **/ValidatePhoneNumber**:

  - Receive by querystring a parameter called *phoneNumber*
  - validate phoneNumber with Spanish format, for example `+34666777888`
  - if phoneNumber is valid return `"valid"`
  - if phoneNumber is not valid return `"invalid"`

> **_NOTE:_** Use above information inside a comment in the `Program.cs` file. Press enter and wait for Copilot to suggest you the code.

- **/ValidateSpanishDNI**:

  - Receive by querystring a parameter called *dni*
  - calculate the DNI letter
  - if DNI is valid return `"valid"`
  - if DNI is not valid return `"invalid"`
  - 98765432M is a valid DNI, 42424242H is an invalid DNI

> **_NOTE:_** Use above information inside a comment in the `Program.cs` file. In this case, you may want to see multiple solutions from Copilot to pick the one that best fits the way to calculate the letter. In order to see the firs 10 suggestions from Copilot press `ctrl + enter`.


## Exercise 3: GitHub Copilot Chat and prompting

>The goal of this exercise is to get familiar with the GitHub Copilot Chat feature and extend the server with additional features.

You can ask Copilot Chat to give code suggestions, explain code, generate unit tests, and suggest code fixes. To open the chat view, click the chat icon in the activity bar or press `Control+Command+i` (Mac) / `Ctrl+Alt+i` (Windows/Linux).

You will be implementing the following additional features:
- [ ] ReturnColorCode
- [ ] TellMeAJoke
- [ ] MoviesByDirector
- [ ] ParseUrl
- [ ] ListFiles

---

### Implement the following:

- **/ReturnColorCode**:

  - Receive by querystring a parameter called *color*
  - read the `colors.json` file and return the *code.rgba* field
  - get color var from the querystring
  - iterate over each color in `colors.json` to find the color
  - return the *code.hex* field

  > **_NOTE:_** Paste the above information in the Copilot Chat window and make it as detailed as possible. Copilot will use by default the open file as context in order to generate the suggestion.

- **/TellMeAJoke**:

  - Make a call to the joke api and return a random joke using axios (https://official-joke-api.appspot.com/random_joke)

  > **_NOTE:_** Here's example where you might need to use you own knowledge and judgement
  > to validate that Copilot follows best practices. Just because Copilot mimic
  > what many developers do, doesn't always mean it's the correct way. You might need
  > to be extra specific in your prompt to let Copilot know what's best practices.
  > _Hint: Pay attention to HttpClient._

- **/MoviesByDirector**:

  - Receive by querystring a parameter called *director*
  - make a call to the movie api and return a list of movies of that director using axios
  - return the full list of movies

  > **_NOTE:_** This will require to browse to https://www.omdbapi.com/apikey.aspx and request a FREE API Key

- **/ParseUrl**:

  - Retrieves a parameter from querystring called *someurl*
  - Parse the url and return the protocol, host, port, path, querystring and hash
  - Return the parsed host

- **/ListFiles**:

  - Get the current directory
  - Get the list of files in the current directory
  - Return the list of files

  > **_NOTE:_** Copilot can also help with these kind of commands locally. The feature is called Copilot in the CLI. You can learn more information about this feature [here](https://docs.github.com/en/copilot/github-copilot-in-the-cli/about-github-copilot-in-the-cli).


## Exercise 4: Refactoring and optimizing

> In this exercise we will use Copilot to refactor existing code

You will be implementing the following additional features:
- [ ] GetFullTextFile
- [ ] GetLineByLineFromTextFile
- [ ] CalculateMemoryConsumption
- [ ] RandomEuropeanCountry

---

- **/GetFullTextFile**:

  - Read `sample.txt` and return lines that contains the word "Fusce"

  > **_NOTE:_** Be careful with this implementation, since this normally reads the full content of the file before analyzing it, so memory usage is high and may fail when files are too big.
  >
  > You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/GetLineByLineFromTextFile**:

  - Read `sample.txt` line by line
  - create a promise to read the file line by line, and return a list of lines that contains the word "Fusce"
  - return the list of lines

  > **_NOTE:_** You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/CalculateMemoryConsumption**:

  - Return the memory consumption of the process in GB, rounded to 2 decimals

- **/RandomEuropeanCountry**:

  - Make an array of european countries and its ISO-codes
  - select a random country from the array
  - return the country and its ISO-code

  > **_NOTE:_** Copilot can help you to generate data sets.


## Exercise 5: Document the code

Documenting code is always a boring and painful task. However, we can use Copilot to document it for us. 

- In the chat, ask Copilot to document the `main.cpp` file by including it using `#main.cpp`.

### Exercise 6: Building tests

We will create automated tests to check that the functionality of the previous endpoints is correctly implemented. The tests should be together in the `MinimalAPI.Tests\IntegrationTests.cs` file.

You can leverage Copilot to run the tests. There is a `/tests` command that you can directly run from Copilot Chat or by selecting the piece of code you want to create tests for and using the Copilot inline feature.

After adding the tests, the tests might be integration tests. Refactor your code to make it testable by unit tests. Push down the integration tests.

### Exercise 7: Create a Dockerfile

Now that we have the new functionality added and tests covering it, lets create a Dockerfile for the Minimal API project.

- Build the image using Copilot and run the app on port 8080
  ```powershell
  docker build -t dotnetapp .
  docker run -d -p 8080:80 --name dotnetapp dotnetapp
  ```

## Summary

With the previous exercises you have gone through some common activities that developers usually run:

- Create new features in the code
- Work with external APIs
- Create documentation
- Create tests

---
Use **slash commands** to avoid writing complex prompts for common scenarios. To use a slash command, type `/` in the chat prompt box, followed by the command name.

- `/clear`: Start a new chat session.
- `/fix`: Propose a fix for problems in the selected code.
- `/explain`: Explain how the code in your active editor works.
- `/tests`: Generate unit tests for the selected code.
- `/fixTestFailure`: Find and fix a failing test.
- ...

Use **chat variables** to include specific context in your prompt. To use a chat variable, type `#` in the chat prompt box, followed by a chat variable.

- `#block`: Includes the current block of code in the prompt.
- `#class`: Includes the current class in the prompt.
- ...

**Chat participants** are like domain experts who have a specialty that they can help you with. You can specify a chat participant by typing `@` in the chat prompt box, followed by a chat participant name. To see all available chat participants, type @ in the chat prompt box.

- `@azure`: Has context about Azure services and how to use, deploy and manage them. Use @azure when you want help with Azure.
- `@terminal`: Has context about the Visual Studio Code terminal shell and its contents. Use @terminal when you want help creating or debugging terminal commands.
- ...

For a full list of command options, please visit the [documentation](https://docs.github.com/en/copilot/using-github-copilot/copilot-chat/github-copilot-chat-cheat-sheet?tool=vscode#slash-commands).
