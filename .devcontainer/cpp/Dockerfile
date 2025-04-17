FROM mcr.microsoft.com/vscode/devcontainers/cpp

# Install required dependencies
RUN apt-get update && apt-get install -y \
    python3-pip 

RUN sudo python3 -m pip install conan --break-system-packages