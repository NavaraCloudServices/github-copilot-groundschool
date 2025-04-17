![alt text](Resources/navara/banner.png)

# GitHub Copilot Ground School

Supporting GitHub repository for the Navara's GitHub Copilot Ground School

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

You need an GitHub Copilot license. You can participate with a free license, however, we expect that you hit the rate limit of the free license during the challenges.

There are three ways to execute the exercises.

### Run on you local machine

Please update your IDE to the latest version. This is important to have the best experience with GitHub Copilot.

Install the Copilot Extension for your IDE:

- [Eclipse Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=eclipse)
- [JetBrains Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=jetbrains)
- [Vim/Nevim Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=vimneovim)
- [Visual Studio](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=visualstudio)
- [Visual Studio Code](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=vscode)
- [Xcode Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=xcode)

Please note, the extensions are already installed in Visual Studio 2022 if you have a recent version.

## Available Exercises

> Please note: The GitHub Workspaces links are 'work in progress'

You can find the exercises [here](./exercisefiles/Exercises_developer.md). Please check the language instructions in the table below

| Language        | Role      | Instructions                                      |
| --------------- | --------- | ------------------------------------------------- |
| C++             | Developer | [Link](./exercisefiles/cpp/README.md)             |
| C#              | Developer | [Link](./exercisefiles/dotnet/README.md)          |
| Java Quarkus    | Developer | [Link](./exercisefiles/java/quarkus/README.md)    |
| Java Springboot | Developer | [Link](./exercisefiles/java/springboot/README.md) |
| PHP             | Developer | [Link](./exercisefiles/php/README.md)             |
| Python          | Developer | [Link](./exercisefiles/python/README.md)          |
| Javascript      | Developer | [Link](./exercisefiles/javascript/README.md)      |
| Typescript      | Developer | [Link](./exercisefiles/typescript/README.md)      |

You can make use of DevContainers within Visual Studio Code. Use the [VSCode documentation to setup your machine](https://code.visualstudio.com/docs/devcontainers/tutorial)
After setting up your machine, go to your Command Pallete in VSCode and select `Dev Containers: Rebuild and open in Container`. This will open the project in a container with all the dependencies installed.

## Challenges instructions

- [Develop a shop cart](./challenges/eshop/eshop.md)
- [Develop a memory game](./challenges/memorygame/memorygame.md)
- [Develop a chat based on websockets](./challenges/chatwebsockets/chatwebsockets.md)
- [Analysis cryptocurrency market analysis](./challenges/cryptoanalisis/crypto.md)
- [COVID19 Worldwide Testing Data (Python Data Engineer)](./challenges/python_data_engineer/README.md)
- [Decision Tree Classicication Based on Diabetest Dataset (Python Data Scientist)](./challenges/python_data_scientist/README.md)

## Quick Links

1. [About GitHub Copilot](https://docs.github.com/en/copilot/about-github-copilot)
2. [Getting started with GitHub Copilot](https://docs.github.com/en/copilot/using-github-copilot/getting-started-with-github-copilot)
3. [About code referencing in GitHub Copilot](https://docs.github.com/en/copilot/using-github-copilot/finding-public-code-that-matches-github-copilot-suggestions)
4. [Using GitHub Copilot Chat in your IDE](https://docs.github.com/en/copilot/github-copilot-chat/using-github-copilot-chat-in-your-ide)
5. [Enabling GitHub Copilot in the CLI](https://docs.github.com/en/copilot/github-copilot-in-the-cli/enabling-github-copilot-in-the-cli)
6. [GitHub Copilot MS Learn Modules](https://learn.microsoft.com/en-us/training/browse/?terms=github%20copilot)
7. [GitHub Copilot Certifications](https://resources.github.com/learn/certifications/)
