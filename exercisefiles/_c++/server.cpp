
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Simulate a server logic:
    // 1) Check if a “key” is passed (like query string).
    // 2) If key is provided, print "hello {key}"
    // 3) Otherwise print "key not passed"
    // 4) Potentially handle other “endpoints” in a switch or if-else.

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg.find("key=") != std::string::npos) {
            auto pos = arg.find("key=");
            std::string value = arg.substr(pos + 4);
            std::cout << "hello " << value << std::endl;
        } else {
            std::cout << "method not supported" << std::endl;
        }
    } else {
        std::cout << "key not passed" << std::endl;
    }

    return 0;
}