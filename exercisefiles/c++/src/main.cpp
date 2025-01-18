// write a c++ server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static std::string parseGetKey(const std::string& request) {
    // Very naive parse to find "key=" in query
    auto pos = request.find("/get?");
    if (pos == std::string::npos) return "";
    auto query = request.substr(pos + 5);
    // find if "key=" is present
    pos = query.find("key=");
    if (pos == std::string::npos) return "missing";
    // extract value
    auto valStart = pos + 4;
    auto valEnd = query.find('&', valStart);
    if (valEnd == std::string::npos) valEnd = query.size();
    return query.substr(valStart, valEnd - valStart);
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(3000);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed.\n";
        return 1;
    }

    std::cout << "server is listening on port 3000" << std::endl;
    listen(server_fd, 5);

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) {
            std::cerr << "Accept error.\n";
            continue;
        }

        char buffer[1024];
        int bytes = read(client_fd, buffer, 1024);
        if (bytes <= 0) {
            close(client_fd);
            continue;
        }
        std::string request(buffer, bytes);

        // Check if GET
        if (request.rfind("GET ", 0) == 0) {
            auto key = parseGetKey(request);
            if (key.empty()) {
                // method might be different
                std::string response = "HTTP/1.1 200 OK\r\n\r\nkey not passed";
                write(client_fd, response.c_str(), response.size());
            } else {
                std::string response = "HTTP/1.1 200 OK\r\n\r\nhello " + key;
                write(client_fd, response.c_str(), response.size());
            }
        } else {
            // method not supported
            std::string response = "HTTP/1.1 200 OK\r\n\r\nmethod not supported";
            write(client_fd, response.c_str(), response.size());
        }
        close(client_fd);
    }

    close(server_fd);
    return 0;
}