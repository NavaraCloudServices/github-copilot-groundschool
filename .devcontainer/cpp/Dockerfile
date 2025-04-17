ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install required dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    ninja-build \
    git \
    curl \
    wget \
    build-essential \
    python3-pip \
    gdb cmake cppcheck \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install conan \
    && conan profile detect