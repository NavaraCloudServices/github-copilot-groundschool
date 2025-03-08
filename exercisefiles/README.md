# Goal

The goal is to create a HTTPServer using the language of your choice. You can find language dependent information in the README.md file in the language folder. 

Follow the instructions below and try to use GitHub Copilot as much as possible.
Try different things and see what GitHub Copilot can do for you, like generating a class, add comments, tests or a Docker file.

> First make sure that you installed the appropriate IDE and SDK's. Follow the [pre-requisites.md](../README.md#pre-requisites) to setup GitHub Copilot for your IDE.

## Exercises

### Exercise 1: Introduction

> The goal of this exercise is to get acquainted with the project files, use basic GitHub Copilot Suggestions/Completion and run the HTTP server and its tests. After this we will start exploring GitHub Copilot features. 

In the exercise folder of your chosen language you can find some language dependent information.

Do the following activities:
- If your language requires it, retrieve the dependencies first. You can find those instructions in the language dependent readme file
- If your language requires it, compile your application
- Run the test that will fail.
- In your main file you can find some code comments. Use GitHub Copilot Suggestions/Completion to implement the basic feature
- Make the test pass

### Exercise 2: Inline suggestions

>The goal of this exercise is using GitHub Copilot Inline suggestions feature to extend the HTTP server endpoints. 

GitHub Copilot offers coding suggestions as you type. GitHub Copilot will automatically suggest the rest of the function. To accept the suggestion, press `Tab`. Within Jetbrains IDE's you can enable code completions with `Alt + \` (Windows) and `Option (⌥) + \` for Mac 

You can also describe something you want to do using natural language within a comment, and Copilot will suggest the code to accomplish your goal.

GitHub Copilot will automatically suggest code. To accept the suggestion, press `Tab`.

Click [here](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot#getting-code-suggestions-2) for more information on Copilot code suggestions


Implement the following methods:

- **/DaysBetweenDates**:

  - Calculate days between two dates
  - receive by query string two parameters `date1` and `date2`, and calculate the days between those two dates.

  > **_NOTE:_** Use above information inside the Copilot inline feature in your server code file. Press enter and wait for Copilot to suggest you the code.

- **/ValidatePhoneNumber**:

  - Receive by querystring a parameter called *phoneNumber*
  - validate phoneNumber with Spanish format, for example `+34666777888`
  - if phoneNumber is valid return `"valid"`
  - if phoneNumber is not valid return `"invalid"`

  > **_NOTE:_** Use above information inside the Copilot inline feature in your server code file. Press enter and wait for Copilot to suggest you the code.

- **/ValidateSpanishDNI**:

  - Receive by querystring a parameter called *dni*
  - calculate the DNI letter
  - if DNI is valid return `"valid"`
  - if DNI is not valid return `"invalid"`
  - 98765432M is a valid DNI, 42424242H is an invalid DNI

  > NOTE: Use above information inside a comment in your server code file. In this case, you may want to see multiple solutions from Copilot to pick the one that best fits the way to calculate the letter. In order to see the firs 10 suggestions from Copilot press `ctrl + enter`.


### Exercise 3: GitHub Copilot Chat and prompting

>The goal of this exercise is to get familiar with the GitHub Copilot Chat feature and extend the server with additional features.

You can ask Copilot Chat to give code suggestions, explain code, generate unit tests, and suggest code fixes. To open the chat view, click the chat icon in the activity bar or press `Control+Command+i` (Mac) / `Ctrl+Alt+i` (Windows/Linux).

Implement the following methods:

- **/ReturnColorCode**:

  - Receive by querystring a parameter called *color*
  - read the `colors.json` file and return the *code.rgba* field
  - get color var from the querystring
  - iterate over each color in `colors.json` to find the color
  - return the *code.hex* field

  > **_NOTE:_** Paste the above information in the Copilot Chat window and make it as detailed as possible. Copilot will use by default the open file as context in order to generate the suggestion.

- **/TellMeAJoke**:

  - Make a call to the joke api and return a random joke using axios (https://official-joke-api.appspot.com/random_joke)

  > **_NOTE:_** The format of the api is as follows: `{ "type":string, "setup":string, "punchline":string, "id":int }`

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

> In this exercise we will use Copilot to refactor existing code. 

Use your prompting skills together with the slash commands. An actual overview can be found on [GitHub docs](https://docs.github.com/en/copilot/using-github-copilot/copilot-chat/github-copilot-chat-cheat-sheet?tool=jetbrains)

Implement the following methods:

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


### Exercise 5: Document the code

> GitHub Copilot can also be used for documenting code. We can use Copilot to document it for us. 

Use your prompting skills together with the slash commands. An actual overview can be found on [GitHub docs](https://docs.github.com/en/copilot/using-github-copilot/copilot-chat/github-copilot-chat-cheat-sheet?tool=jetbrains).

In the chat, ask Copilot to document your code. Tip: use the `#file` option if available

### Exercise 6: Building tests

> Use GitHub Copilot for your testing. We will create automated tests to check that the functionality of the previous endpoints is correctly implemented. 

You can leverage Copilot to run the tests. There is a `/tests` command that you can directly run from Copilot Chat or by selecting the piece of code you want to create tests for and using the Copilot inline feature.

After adding the tests, the tests might be integration tests. Refactor your code to make it testable by unit tests. Push down the integration tests so that you have unit test coverage.

If you use Visual Studio or Visual Studio code, you might want to try GitHub Copilot Edits (Visual Studio Code) or GitHub Copilot Tool Calling (Visual Studio)

### Exercise 7: Create a Dockerfile

> Let's do some DevOpsy stuff

Now that we have the new functionality added and tests covering it, lets create a Dockerfile to host your application

Build the image using Copilot and expose the port `3000`. Use all the GitHub Copilot features you want.