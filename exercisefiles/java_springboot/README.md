# Goal

The goal is to create a server using Java,Maven & SprintBoot with the help of GitHub Copilot. Follow the instructions below and try to use GitHub Copilot as much as possible.

Try different things and see what GitHub Copilot can do for you.

## Exercises

### Exercise 1: Introduction

- Go to the exercisefile folder
- Go to the [CopilotDemoApplication.java](exercisefiles/java_springboot/src/main/java/com/microsoft/hackathon/copilotdemo/CopilotDemoApplication.java) file and start writing the code to handle a simple GET request. In this first exercise, we have provided a comment that describes the code you need to generate. Just press enter and wait a couple of seconds, Copilot will generate the code for you.

> Tip: If nothing happens, then change the comment (add a word or 2) - sometimes Copilot needs a little nudge.

There is already a test implemented for this exercise.

After every exercise, feel free to package and run your application to test it.

Package: `mvn package`

Run: `mvn spring-boot:run`

Test: `curl -v http://localhost:8080/hello?key=world`

### Exercise 2: Inline suggestions

The exercise consist of building a web server using Nodejs that serves the request of various functionality.

The requests that the server must attend are the following:

- **/DaysBetweenDates**:

  - Calculate days between two dates
  - receive by query string 2 parameters date1 and date 2, and calculate the days between those two dates.

  > **_NOTE:_** Use above information inside the Copilot inline feature in the `CopilotDemoApplication.java` file. Press enter and wait for Copilot to suggest you the code.

- **/Validatephonenumber**:

  - Receive by querystring a parameter called phoneNumber
  - validate phoneNumber with Spanish format, for example +34666777888
  - if phoneNumber is valid return "valid"
  - if phoneNumber is not valid return "invalid"

  > **_NOTE:_** Use above information inside the Copilot inline feature in the `CopilotDemoApplication.java` file. Press enter and wait for Copilot to suggest you the code.

- **/ValidateSpanishDNI**:

  - Receive by querystring a parameter called dni
  - calculate DNI letter
  - if DNI is valid return "valid"
  - if DNI is not valid return "invalid"

  - 98765432M is a valid DNI, 42424242H is an invalid DNI

  > NOTE: Use above information inside a comment in the `CopilotDemoApplication.java` file. In this case, you may want to see multiple solutions from Copilot to pick the one that best fits the way to calculate the letter. In order to see the firs 10 suggestions from Copilot press ctrl + enter.

### Exercise 3: GitHub Copilot Chat and prompting

- **/ReturnColorCode**:

  - Receive by querystring a parameter called color
  - read colors.json file and return the rgba field
  - get color var from querystring
  - iterate for each color in colors.json to find the color
  - return the code.hex field

  > NOTE: Lets try Copilot chat now. Paste the above information and make it as detailed as possible in the Copilot chat text box. Copilot will use by default the open file as context in order to generate the suggestion.

- **/TellMeAJoke**:

  - Make a call to the joke api and return a random joke using axios (https://official-joke-api.appspot.com/random_joke)

- **/MoviesByDirector**:

  - Receive by querystring a parameter called director
  - Make a call to the movie api and return a list of movies of that director using axios
  - Return the full list of movies

  > **_NOTE:_** This will require to browse to https://www.omdbapi.com/apikey.aspx and request a FREE API Key

- **/ParseUrl**:

  - Retrieves a parameter from querystring called someurl
  - Parse the url and return the protocol, host, port, path, querystring and hash
  - Return the parsed host

- **/ListFiles**:

  - Get the current directory
  - Get the list of files in the current directory
  - Return the list of files

  > **_NOTE:_** Copilot can also help with these kind of commands locally. The feature is called Copilot in the CLI. You can learn more information about this feature [here](https://docs.github.com/en/copilot/github-copilot-in-the-cli/about-github-copilot-in-the-cli).

### Exercise 4: Refactoring and optimizing

- **/GetFullTextFile**:

  - Read `sample.txt`` and return lines that contains the word "Fusce"

  > **_NOTE:_** Becareful with this implementation, since this normally reads the full content of the file before analizing it, so memory usage is high and may fail when files are too big.
  >
  > You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/GetLineByLinefromtTextFile**:

  - Read `sample.txt` line by line (this is in the resources folder)
  - Create a promise to read the file line by line, and return a list of lines that contains the word "Fusce"
  - Return the list of lines

  > **_NOTE:_** You can use Copilot Code completion or inline chat. Once done you can also use Copilot Inline Chat to refactor the code to put this logic in a function.

- **/CalculateMemoryConsumption**:

  - Return the memory consumption of the process in GB, rounded to 2 decimals

- **/RandomEuropeanCountry**:

  - Make an array of european countries and its iso codes
  - Return a random country from the array
  - Return the country and its iso code

  > **_NOTE:_** Copilot can help you to generate data sets.

### Exercise 5: Document the code

Documenting code is always a boring and painful task. However, we can use Copilot to document it for us. In the chat, ask Copilot to document the `CopilotDemoApplication.java` file.

### Exercise 6: Building tests

We will create automated tests to check that the functionality of the previous endpoints is correctly implemented. The tests should be together in the `CopilotDemoApplicationTests.java` file.

You can leverage Copilot to create the tests. There is a `/tests` command that you can directly run from Copilot Chat or by selecting the piece of code you want to create tests for and using the Copilot inline feature.

After adding the tests, the tests might be integration tests. Refactor your code to make it testable by unit tests. Push down the integration tests.

### Exercise 7: Create a Dockerfile

Use the Dockerfile provided to create a docker image of the application. There are some comments in the Dockerfile that will help you to complete the exercise.

In order to build, run and test the docker image, you can use Copilot as well to generate the commands.

For instance, create a DOCKER.md file where you can store the commands to build, run and test the docker image. You will notice that Copilot will also help you to document your project and commands.

Examples of steps to document: Build the container image, Run the container, Test the container.

## Summary

With the previous exercises you have gone through some common activities that developers usually run:

- Create new features in the code
- Work with external APIs
- Create documentation
- Create tests

However, there are many other things that Copilot can help you with. Feel free to explore other slash command in the Copilot chat like:

- `/fix`: to fix the problems in your code
- `/explain`: for Copilot to explain you what the code does