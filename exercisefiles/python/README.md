[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fphp%2Fdevcontainer.json)

# Goal

The goal is to create a Minimal WebAPI using Python 3 with the help of GitHub Copilot. 
Follow the instructions below and try to use GitHub Copilot as much as possible.
Try different things and see what GitHub Copilot can do for you, like generating a Dockerfile or a class, add comments, etc.

> Make sure GitHub Copilot is configured and enabled for the current language, just check the status bar on the bottom right corner of VS Code.

## Exercises


### Exercise 1: Introduction

>The goal of this exercise is to get acquainted with the project files, run the HTTP server and its tests. After this we will start exploring GitHub Copilot features. 

- Go to the `exercisefiles/developer` folder
- Open `server.py` and begin by writing a Python server, check the first suggestions based on the initial text
- Open `test.py` file and analyze the current test
- Use `pytest` to run the tests
- Open a command prompt and run the test (`pytest test.py`)
- See the result, it should display something like:
  ```bash
  pytest test.py
  server is listening on port 3000

    Node Server

      √ should return "key not passed" if key is not passed

    1 passing (34ms)
  ```


### Exercise 2: Inline suggestions

>The goal of this exercise is using GitHub Copilot Inline suggestions feature to extend the HTTP server endpoints. 

GitHub Copilot offers coding suggestions as you type. GitHub Copilot will automatically suggest the rest of the function. To accept the suggestion, press `Tab`. Within Jetbrains IDE's you can enable code completions with `Alt + \` (Windows) and `Option (⌥) + \` for Mac 

You can also describe something you want to do using natural language within a comment, and Copilot will suggest the code to accomplish your goal. For example, type this comment in a JavaScript file:

GitHub Copilot will automatically suggest code. To accept the suggestion, press `Tab`.

Click [here](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot#getting-code-suggestions-2) for more information on Copilot code suggestions

You will be implementing the following additional features:
- [ ] Get
- [ ] DaysBetweenDates
- [ ] ValidatePhoneNumber
- [ ] ValidateSpanishDNI

---

#### Implement the following:

- **/Get**:

  - Return a hello world message

- **/DaysBetweenDates**:

  - Calculate days between two dates
  - receive by query string two parameters `date1` and `date2`, and calculate the days between those two dates.

  > **_NOTE:_** Use above information inside the Copilot inline feature in the `server.py` file. Press enter and wait for Copilot to suggest you the code.

- **/ValidatePhoneNumber**:

  - Receive by querystring a parameter called *phoneNumber*
  - validate phoneNumber with Spanish format, for example `+34666777888`
  - if phoneNumber is valid return `"valid"`
  - if phoneNumber is not valid return `"invalid"`

  > **_NOTE:_** Use above information inside the Copilot inline feature in the `server.py` file. Press enter and wait for Copilot to suggest you the code.

- **/ValidateSpanishDNI**:

  - Receive by querystring a parameter called *dni*
  - calculate the DNI letter
  - if DNI is valid return `"valid"`
  - if DNI is not valid return `"invalid"`
  - 98765432M is a valid DNI, 42424242H is an invalid DNI

  > NOTE: Use above information inside a comment in the `server.py` file. In this case, you may want to see multiple solutions from Copilot to pick the one that best fits the way to calculate the letter. In order to see the first 10 suggestions from Copilot press `ctrl + enter`.


### Exercise 3: GitHub Copilot Chat and prompting

>The goal of this exercise is to get familiar with the GitHub Copilot Chat feature and extend the server with additional features.

You can ask Copilot Chat to give code suggestions, explain code, generate unit tests, and suggest code fixes. To open the chat view, click the chat icon in the activity bar or press `Control+Command+i` (Mac) / `Ctrl+Alt+i` (Windows/Linux).

You will be implementing the following additional features:
- [ ] ReturnColorCode
- [ ] TellMeAJoke
- [ ] MoviesByDirector
- [ ] ParseUrl
- [ ] ListFiles

---

#### Implement the following:

- **/ReturnColorCode**:

  - Receive by querystring a parameter called *color*
  - read the `colors.json` file and return the *code.rgba* field
  - get color var from the querystring
  - iterate over each color in `colors.json` to find the color
  - return the *code.hex* field

  > **_NOTE:_** Paste the above information in the Copilot Chat window and make it as detailed as possible. Copilot will use by default the open file as context in order to generate the suggestion.

- **/TellMeAJoke**:

- **/TellMeAJoke**:

  - Make a call to the joke api and return a random joke using axios (https://official-joke-api.appspot.com/random_joke)

  > **_NOTE:_** Here's example where you might need to use you own knowledge and judgement
  > to validate that Copilot follows best practices. 

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


### Exercise 4: Refactoring and optimizing

> In this exercise we will use Copilot to refactor existing code

You will be implementing the following additional features:
- [ ] GetFullTextFile
- [ ] GetLineByLineFromTextFile
- [ ] CalculateMemoryConsumption
- [ ] RandomEuropeanCountry

---

#### Implement the following:

- **/GetFullTextFile**:

  - Read `sample.txt` and return lines that contains the word "Fusce"

  > **_NOTE:_** Be careful with this implementation, since this normally reads the full content of the file before analyzing it, so memory usage is high and may fail when files are too big.
  >
  > You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/GetLineByLinefromTextFile**:

  - Read `sample.txt` line by line
  - Create a promise to read the file line by line, and return a list of lines that contain the word "Fusce"
  - Return the list of lines

  > **_NOTE:_** You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/CalculateMemoryConsumption**:

  - Return the memory consumption of the process in GB, rounded to 2 decimals

- **/RandomEuropeanCountry**:

  - Make an array of european countries and its ISO-codes
  - select a random country from the array
  - return the country and its ISO-code

  > **_NOTE:_** Copilot can help you to generate data sets.

### Exercise 5: Document the code

Documenting code is always a boring and painful task. However, we can use Copilot to document it for us. 

- In the chat, ask Copilot to document the `server.py` file.

### Exercise 6: Building tests

We will create automated tests to check that the functionality of the previous endpoints is correctly implemented. The tests should be together in the `test.py` file.

You can leverage Copilot to run the tests. There is a `/tests` command that you can directly run from Copilot Chat or by selecting the piece of code you want to create tests for and using the Copilot inline feature.

After adding the tests, the tests might be integration tests. Refactor your code to make it testable by unit tests. Push down the integration tests.

### Exercise 7: Create a Dockerfile

Now that we have the new functionality added and tests covering it, lets create a Dockerfile for the Python Application.

- Build the image using Copilot and expose the port 3000.

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
