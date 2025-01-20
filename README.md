# GitHub Copilot Ground School

Supporting GitHub repository for the GitHub Copilot Ground School

- [Goal](#goal)
- [Pre-requisites](#pre-requisites)
- [Install Development Tools](#install-development-tools)
- [Exercises](#exercises)
- [Other Exercises](#other-exercises)
- [Challenges instructions](#challenges-instructions)
- [Quick Links](#quick-links)

## Forked from

This repository is forked from the [Microsoft Copilot Hackathon](https://github.com/microsoft/CopilotHackathon)

## Goal

The goal of a GitHub Copilot Ground School is to learn how to use it through a set of [Exercises](#exercises)(#labs-instructions). These exercises consist of building a web server using Nodejs with different functionalities, a .NET Web API, C++, Python or a Java Rest API (either Spring Boot or Quarkus).

For those who are already familiar with GitHub Copilot, we have also defined a series of [challenges](#challenges-instructions) to test your skills. You will find an introduction and short guidance to help you solve the challenge, but you will have to do most of the work on your own (with the help of Copilot, of course).

GitHub Copilot is an AI-powered code assistant that helps developers write better code faster. It uses machine learning models trained on billions of lines of code to suggest whole lines or entire functions based on the context of what you’re working on. By using Copilot, you can learn how to write better code and improve your productivity.

Remember:

- As you type, GitHub Copilot will make suggestions, you can accept them by pressing Tab.
- If nothing shows up after Copilot writes some lines, press enter and wait a couple of seconds.
- Press **Ctrl + Enter**, to see more suggestions.
- Use Copilot chat to support your learning and development.
- Press **Ctrl + i** to start Copilot chat inline within your code.

## Pre-requisites

### GitHub Copilot access

If you still do not have an active Copilot license, a 30 day trial can be requested [here](https://github.com/github-copilot/signup).

### IDE Extensions

Please update your IDE to the latest version. This is important to have the best experience with GitHub Copilot.

Install the Copilot Extension for your IDE:

- [Visual Studio Code Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=vscode)
- [JetBrains Copilot Extension](https://docs.github.com/en/copilot/using-github-copilot/getting-code-suggestions-in-your-ide-with-github-copilot?tool=jetbrains)

Please note, the extensions are already installed in Visual Studio 2022 if you have a recent version. You need to log in to use them:

- [Visual Studio 2022 Copilot Extension](https://learn.microsoft.com/en-us/visualstudio/ide/visual-studio-github-copilot-extension?view=vs-2022)
- [Visual Studio 2022 Copilot Chat Extension](https://learn.microsoft.com/en-us/visualstudio/ide/visual-studio-github-copilot-chat?view=vs-2022)

### Install Copilot CLI

Follow the instructions for your operating system:

- [Install GitHub CLI](https://github.com/cli/cli#installation)
- [Install GitHub Copilot CLI Extension](https://docs.github.com/en/copilot/managing-copilot/configure-personal-settings/installing-github-copilot-in-the-cli)
- [Configuring GitHub Copilot in the CLI](https://docs.github.com/en/copilot/managing-copilot/configure-personal-settings/configuring-github-copilot-in-the-cli)
    (Please note: For Windows, this only works for PowerShell Core.)

## Install Development Tools

### VisualStudio Code

- [Download and install](https://code.visualstudio.com/)

### Node.js and Typescript

- [Install Node and npm](https://docs.npmjs.com/downloading-and-installing-node-js-and-npm)
- Install Mocha:

Run:

``` bash
 npm install --global mocha
 npm install axios
```

### .NET

[Install .NET](https://dotnet.microsoft.com/download)

### Java and Maven

- [Install Java (OpenJDK)](https://learn.microsoft.com/en-us/java/openjdk/install)
- [Install Maven](https://maven.apache.org/install.html)

### Python

- [Install Python](https://www.python.org/downloads/)

### C++

- [Install CMake](https://cmake.org/download/)

### PHP

- [Install PHP](https://www.php.net/manual/en/install.php)
- [Install Composer](https://getcomposer.org/download/)

## Exercises

- [C++](./exercisefiles/c++/README.md)
- [Node Server](./exercisefiles/node/README.md)
- [Node Server Typescript](./exercisefiles/node_typescript/README.md)
- [.NET](./exercisefiles/dotnet/README.md)
- [Java Spring Boot](./exercisefiles/java_springboot/README.md)
- [Java Quarkus](./exercisefiles/java_quarkus/README.md)
- [Python](./exercisefiles/python/README.md)

## Other Exercises

- [Python Data Engineer](./exercisefiles/python_dataengineer/README.md)
- [Python Data Scientist](./exercisefiles/python_datascientist/README.md)
- [C++ Okto Converter](./exercisefiles/c++_octoconverter/README.md)

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
