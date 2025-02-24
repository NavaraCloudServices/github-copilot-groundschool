ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Install required dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    ninja-build \
    git \
    curl \
    wget \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Install CMake 3.31+ (instead of the default version in apt)
RUN wget https://cmake.org/files/v3.31/cmake-3.31.0-Linux-x86_64.sh -O /tmp/cmake.sh \
    && chmod +x /tmp/cmake.sh \
    && /tmp/cmake.sh --prefix=/usr/local --skip-license \
    && rm -f /tmp/cmake.sh