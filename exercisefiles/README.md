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

You can also describe something you want to do using natural language within a comment, and GitHub Copilot will suggest the code to accomplish your goal.

GitHub Copilot will automatically suggest code. To accept the suggestion, press `Tab`.

Click [here](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot#getting-code-suggestions-2) for more information on GitHub Copilot code suggestions


Implement the following methods:

#### **/SecondsBetweenTimeStamps**:

  - Calculate seconds between two timestamps
  - receive by query string two parameters `timestamp1` and `timestamp2`, and calculate the seconds between those two timestamps.
  - If you want, add some validation

  > **_NOTE:_** Use above information inside the GitHub Copilot inline feature in your server code file. Press enter and wait for GitHub Copilot to suggest you the code.

#### **/ValidateDutchPhoneNumber**:

  - Receive by querystring a parameter called *phoneNumber*
  - validate phoneNumber with Dutch format, for example `+31612345678`
  - if phoneNumber is valid return `"valid"`
  - if phoneNumber is not valid return `"invalid"`

  > **_NOTE:_** Use above information inside the GitHub Copilot inline feature in your server code file. Press enter and wait for GitHub Copilot to suggest you the code.

#### **/ValidateDutchBSN**:

  - Receive by querystring a parameter called *bsn*
  - Make it comply to the '11 proef'
  - if BSN is valid return `"valid"`
  - if BSN is not valid return `"invalid"`
  - Provide examples in your prompt as comment
  - Examples:
    - 267868303 - valid
    - 051464548 - valid
    - 051424548 - invalid
    - 262868303 - invalid

  > NOTE: Use above information inside a comment in your server code file. In this case, you may want to see multiple solutions from GitHub Copilot to pick the one that best fits the way to calculate the letter. In order to see the firs 10 suggestions from GitHub Copilot press `ctrl + enter`.

### Exercise 3: GitHub Copilot Chat and prompting

>The goal of this exercise is to get familiar with the GitHub Copilot Chat feature and extend the server with additional features.

You can ask GitHub Copilot Chat to give code suggestions, explain code, generate unit tests, and suggest code fixes. To open the chat view, click the chat icon in the activity bar or press `Control+Command+i` (Mac) / `Ctrl+Alt+i` (Windows/Linux).

Implement the following methods:

#### **/ReturnColorHexCode**:

  - Receive by querystring a parameter called *colorName*
  - read the `colors.json` file and return the *hex* field of the right collor

  > **_NOTE:_** Paste the above information in the GitHub Copilot Chat window and make it as detailed as possible. GitHub Copilot will use by default the open file as context in order to generate the suggestion.

#### **/GiveMeARandomChuckNorrisQuote**:

  - Make a call to the chuck noris api and return a random chuck noris quote. The API can be found here: (https://api.chucknorris.io)

#### **/ListAllGameOfThronesEpisodesBySeason**:

  - Receive by querystring a parameter called *season*
  - Make a call to the movie api and return the lists of episodes of that Game Of Thrones season

  > **_NOTE:_** This will require to browse to https://www.omdbapi.com/apikey.aspx and request a FREE API Key

#### **/ValidateDutchIBAN**:

  - Receive by querystring a parameter called *iban*
  - if IBAN is valid return `"valid"`
  - if IBAN is not valid return `"invalid"`
  - Provide examples in your prompt as comment

#### **/ListFiles**:

  - Get the current directory
  - Get the list of files in the current directory
  - Return the list of files

  > **_NOTE:_** GitHub Copilot can also help with these kind of commands locally. The feature is called GitHub Copilot in the CLI. You can learn more information about this feature [here](https://docs.github.com/en/copilot/github-copilot-in-the-cli/about-github-copilot-in-the-cli).


### Exercise 4: Refactoring and optimizing

> In this exercise we will use GitHub Copilot to refactor existing code. 

Use your prompting skills together with the slash commands. An actual overview can be found on [GitHub docs](https://docs.github.com/en/copilot/using-github-copilot/copilot-chat/github-copilot-chat-cheat-sheet?tool=jetbrains)

Implement the following methods:

#### **/GetFullTextFile**:

  - Read `sample.txt` and return lines that contains the word "lacinia"

  > **_NOTE:_** Be careful with this implementation, since this normally reads the full content of the file before analyzing it, so memory usage is high and may fail when files are too big.

  > Start with implementing the logic by yourself using GitHub Copilot Code completion. Then ask GitHub Copilot Chat to refactor the code to use a more memory efficient way of reading the file. 

#### **/RandomEuropeanCountry**:

  - Make an array of european countries and its ISO-codes
  - select a random country from the array
  - return the country and its ISO-code

  > **_NOTE:_** GitHub Copilot can help you to generate data sets.

#### Make Controllers

As you might have noticed, the code is getting a bit messy. We can use GitHub Copilot to create controllers for our endpoints. This will help us to separate the logic of the endpoints from the logic of the application and make it more readable, maintainable and testable.

  > Use GitHub Copilot Edits to create controllers for the endpoints. Use your prompting skills to enhance the implementation and ensure best practices are followed.

### Exercise 5: Document the code

> GitHub Copilot can also be used for documenting code. We can use GitHub Copilot to document it for us. 

Use your prompting skills together with the slash commands. An actual overview can be found on [GitHub docs](https://docs.github.com/en/copilot/using-github-copilot/copilot-chat/github-copilot-chat-cheat-sheet?tool=jetbrains).

In the chat, ask GitHub Copilot to document your code. Tip: use the `#file` option if available

### Exercise 6: Building tests

Use GitHub Copilot for your testing. We will create automated tests to check that the functionality of the previous endpoints is correctly implemented. Create both unit tests and integration tests.

> If you are using Visual Studio Code, you can try out GitHub Copilot Chat Agent to iterate over the code and test outcomes.

### Exercise 7: Create a Dockerfile

> Let's do some DevOpsy stuff

Now that we have the new functionality added and tests covering it, lets create a Dockerfile to host your application

Build the image using GitHub Copilot and expose the port `3000`. Use all the GitHub Copilot features you want.