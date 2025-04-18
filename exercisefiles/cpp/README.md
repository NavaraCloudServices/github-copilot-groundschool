# CPP

You can find the exercises [here](../Exercises_developer.md).

## Prerequisites

We recommend running this in a devcontainer or GitHub Codespace. If you are running locally, please ensure you have the following installed:

- [Conan package manager](https://conan.io/downloads) (if not installed, run `pip install conan`)
- Set default Conan profile `conan profile detect`
- CMake (version 3.18 or higher)
- Make or another build system supported by CMake

### Installing Prerequisites

#### macOS
```bash
# Install using Homebrew
brew install cmake conan

# Make is usually pre-installed on macOS, but you can ensure it's installed with:
brew install make
```

#### Linux (Ubuntu/Debian)
```bash
# Install CMake
sudo apt-get update
sudo apt-get install cmake build-essential

# Install Conan
pip install conan
```

#### Windows
```bash
# Install CMake
# Download and install from https://cmake.org/download/

# Install Conan
pip install conan

# For Make on Windows, you can use MinGW, MSYS2, or Visual Studio's build tools
```

## Main File

- `src/main.cpp`

## Tests File

- `test/tests.cpp`

## How to Compile?

1. Install dependencies with Conan and generate build files:
```bash
mkdir build && cd build
conan install .. --build=missing -s compiler.cppstd=gnu17
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## How to Start the Server?

- After building, run `./src/httpserver` from the build directory

## How to Start the Tests?

- After building, run `./test/tests` from the build directory