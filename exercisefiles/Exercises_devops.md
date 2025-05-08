# Goal

The goal is to create Scripts (Bash/PowerShell) and Infrastructure as Code (Terraform or Bicep).

Follow the instructions below and try to use GitHub Copilot as much as possible.
Try different things and see what GitHub Copilot can do for you, like generating your code, add comments, tests or a Docker file.

> First, follow the [pre-requisites.md](../README.md#pre-requisites) to setup GitHub Copilot for your IDE.

## Exercises


>The goal of this exercise is to verify if GitHub Copilot is working.

You are managing a CI/CD pipeline that stores deployment artifacts in a directory (or a storage bucket, optional). Over time, these artifacts pile up, consuming unnecessary storage.

Your task is to write a Bash or PowerShell script that:
- Delete deployment artifacts older than N days.

See the [scripts](/scripts/) directory.

Create the script as you normally would do. You will notice that GitHub Copilot will suggest code as you type. You can accept the suggestions by pressing `Tab` or `Enter`.

### Exercise 2: Inline suggestions

>The goal of this exercise is to transform your comments to working code as you type.

GitHub Copilot offers coding suggestions as you type. GitHub Copilot will automatically suggest the rest of the function. To accept the suggestion, press `Tab`. Within Jetbrains IDE's you can enable code completions with `Alt + \` (Windows) and `Option (⌥) + \` for Mac 

You can describe something you want to do using natural language within a comment, and GitHub Copilot will suggest the code to accomplish your goal. Use your fresh prompting skill to first type in your requirement as a code comment.

GitHub Copilot will automatically suggest code. To accept the suggestion, press `Tab`.

Click [here](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot#getting-code-suggestions-2) for more information on GitHub Copilot code suggestions

Implement the following:

#### Extend your cleanup script 

Extend your cleanup script to include the following functionality:
- Add a dry-run option (list of files/directories to be deleted)
- Make it recursive
- Logs the deleted files to a log file.
- Parameterize it (e.g., --dry-run, --days, --path, etc.)

#### Create a pipeline

Create a pipeline that runs the script. You can use GitHub Actions, Azure DevOps, or any other CI/CD tool you prefer. GitHub Copilot helps you understanding the tool you use by put it in a comment in your yaml file

#### Add more requirements to your cleanup script

Extend your cleanup script to include the following functionality:
- Make it runnable on Windows and Linux
- Add robust error handling:
   - If a file can’t be deleted, log the error
   - Retry a few times
- When a file cannot be deleted send out a notification by e-mail or slack

### Exercise 3: GitHub Copilot Chat and prompting

>The goal of this exercise is to get familiar with the GitHub Copilot Chat feature.

You can ask GitHub Copilot Chat to give code suggestions, explain code, generate unit tests, and suggest code fixes. To open the chat view, click the chat icon in the activity bar or press `Control+Command+i` (Mac) / `Ctrl+Alt+i` (Windows/Linux).

Implement the following methods:

#### Create a Basic VM with Terraform (AWS or Azure) or Bicep (Azure only)

You can work in the [terraform](./terraform/) or [bicep](./bicep/) directory.

Create a VM with the following specs:
- a 16GB RAM instance
- 4 vCPUs
- Ubuntu 22.04 LTS
- Public IP
- SSH key pair
- No VPC or VNET

> With common infrastructure as code you will receive the 'matched public code' message often. You can work around this by specifying unique names for your resources. Name them after your favorite movie, book or serie characters.

> Use the above information in the GitHub Copilot Chat window to create a prompt and make it as detailed as possible. GitHub Copilot will use by default the open file as context in order to generate the suggestion so close this readme.

####  Basic Networking

- Add a VPC or VNET
- Add a subnet
- Put the VM in the subnet

#### Create Storage (S3 or Blob)

- Create a storage account (S3 or Blob Storage)
- Configure access policies
- Set up lifecycle management rules

### Exercise 4: Refactoring and optimizing

>The goal of this exersize is to refactor your code from Exercise 3.

#### Use Variables, Outputs and Modules

- Move hardcoded values to variable files.
- Create modules for re-usability.
- For Bicep, create a main.bicep file that calls the modules including the input parameters
- For Terraform, create a main.tf file that calls the modules.

#### Make environmentindpendent

- Your organization has multiple environments (dev, tst, prd). Make sure your code is environment independent. All resources should be created in the same way, regardless of the environment but with a postfix with the environment name.

### Exercise 5: Document the code

>The goal is to let GitHub Copilot generate documentation. 

In the chat, ask GitHub Copilot to document your code. Tip: use the `#file` option if available. Write both inline comments and a README.md file.

### Exercise 6: Building tests

>The goal is to let GitHub Copilot write tests for your code.

With terratest (based on Go) you can write tests for your terraform code. You can find a basic setup in the [test](./test/) directory. You can use the built-in Visual Studio Code test runner or the command line to run the tests.

> If you are using Visual Studio Code, you can try out GitHub Copilot Chat Agent to iterate over the code and test outcomes.
