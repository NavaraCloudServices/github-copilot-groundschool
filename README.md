![alt text](Resources/navara/banner.png)


# GitHub Copilot Ground School

Supporting GitHub repository for the GitHub Copilot Ground School

- [Goal](#goal)
- [Pre-requisites](#pre-requisites)
- [Exercises](#available-exercises)
- [Challenges instructions](#challenges-instructions)
- [Quick Links](#quick-links)

## Forked from

This repository was forked from the official [Microsoft Copilot Hackathon](https://github.com/microsoft/CopilotHackathon). Thank you to the Microsoft team for their great work!

## Goal

The goal of a GitHub Copilot Ground School is to learn how to use it through a set of [Exercises](#exercises). These exercises consist of building a web server using Nodejs with different functionalities, a .NET Web API, C++, Python or a Java Rest API (either Spring Boot or Quarkus).

For those who are already familiar with GitHub Copilot, we have also defined a series of [Challenges](#challenges-instructions) to test your skills. You will find an introduction and short guidance to help you solve the challenge, but you will have to do most of the work on your own (with the help of Copilot, of course).

GitHub Copilot is an AI-powered code assistant that helps developers write better code faster. It uses machine learning models trained on billions of lines of code to suggest whole lines or entire functions based on the context of what you’re working on. By using Copilot, you can learn how to write better code and improve your productivity.

Remember:

- As you type, GitHub Copilot will make suggestions, you can accept them by pressing Tab.
- If nothing shows up after Copilot writes some lines, press enter and wait a couple of seconds.
- Press **Ctrl + Enter**, to see more suggestions.
- Use Copilot chat to support your learning and development.
- Press **Ctrl + i** to start Copilot chat inline within your code.

## Pre-requisites

You can make these exercises either using [GitHub Codespaces](https://github.com/features/codespaces), or locally using [dev containers](https://containers.dev) in VS Code. These containerized instances install the required dependencies en setup the environment needed to perform the exercises, no additional configuration needed!

### GitHub Copilot access

If you still do not have an active Copilot license, a 30 day trial can be requested [here](https://github.com/github-copilot/signup).

## Available Exercises

| Language | Role | Exercises | GitHub Codespaces |
|---|---|---|---|
| C++ | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/cpp) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fcpp%2Fdevcontainer.json) |
| C# | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/dotnet) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fdotnet%2Fdevcontainer.json) |
| Java Quarkus | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/java/quarkus) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fjava_quarkus%2Fdevcontainer.json) |
| Java Springboot | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/java/springboot) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fjava_springboot%2Fdevcontainer.json) |
| PHP | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/php) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fphp%2Fdevcontainer.json) |
| Python | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/python/developer) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fpython%2Fdevcontainer.json) |
| Python | Data Engineer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/python/data_engineer) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fpython%2Fdevcontainer.json) |
| Python | Data Scientist | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/python/data_scientist) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fpython%2Fdevcontainer.json) |
| Javascript | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/javascript) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Fjavascript-node%2Fdevcontainer.json) |
| Typescript | Developer | [Link](https://github.com/NavaraCloudServices/github-copilot-groundschool/tree/main/typescript) | [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/NavaraCloudServices/github-copilot-groundschool/tree/main?devcontainer_path=.devcontainer%2Ftypescript-node%2Fdevcontainer.json) |

## Challenges instructions

- [Develop a shop cart](./challenges/eshop/eshop.md) 
- [Develop a memory game](./challenges/memorygame/memorygame.md)
- [Develop a chat based on websockets](./challenges/chatwebsockets/chatwebsockets.md)
- [Behavior Driven Development (BDD) challenge for Java](./challenges/bdd/README.md)
- [Analysis cryptocurrency market analysis](./challenges/cryptoanalisis/crypto.md)

## Quick Links

1. [About GitHub Copilot](https://docs.github.com/en/copilot/about-github-copilot)
2. [Getting started with GitHub Copilot](https://docs.github.com/en/copilot/using-github-copilot/getting-started-with-github-copilot)
3. [About code referencing in GitHub Copilot](https://docs.github.com/en/copilot/using-github-copilot/finding-public-code-that-matches-github-copilot-suggestions)
4. [Using GitHub Copilot Chat in your IDE](https://docs.github.com/en/copilot/github-copilot-chat/using-github-copilot-chat-in-your-ide)
5. [Enabling GitHub Copilot in the CLI](https://docs.github.com/en/copilot/github-copilot-in-the-cli/enabling-github-copilot-in-the-cli)
6. [GitHub Copilot MS Learn Modules](https://learn.microsoft.com/en-us/training/browse/?terms=github%20copilot)
7. [GitHub Copilot Certifications](https://resources.github.com/learn/certifications/)