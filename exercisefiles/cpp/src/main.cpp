// write a c++ server that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"
// Use modern c++17 features
// favor compile-time features over runtime features
// Use c++ standard library only, no third party libraries
// Use design patterns where appropriate
// Do not use asio

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <regex>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>

class SimpleHttpServer {
public:
    SimpleHttpServer(int port) : port(port) {}

    void start() {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0) {
            perror("Socket failed");
            exit(EXIT_FAILURE);
        }

        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }

        if (listen(server_fd, 3) < 0) {
            perror("Listen failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "server is listening on port " << port << std::endl;

        while (true) {
            int addrlen = sizeof(address);
            int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
            if (new_socket < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            std::thread(&SimpleHttpServer::handleClient, this, new_socket).detach();
        }
    }

private:
    int port;

    void handleClient(int client_socket) {
        char buffer[1024] = {0};
        read(client_socket, buffer, 1024);

        std::string request(buffer);
        std::string response = processRequest(request);

        send(client_socket, response.c_str(), response.size(), 0);
        close(client_socket);
    }

    std::string processRequest(const std::string& request) {
        std::istringstream request_stream(request);
        std::string method, url, protocol;
        request_stream >> method >> url >> protocol;

        if (method != "GET") {
            return buildResponse("405 Method Not Allowed", "method not implemented");
        }

        auto query_params = parseQueryParams(url);
        if (url.find("/hello") == 0) {
            if (query_params.find("name") != query_params.end()) {
                return buildResponse("200 OK", "hello " + query_params["name"]);
            } else {
                return buildResponse("200 OK", "name not passed");
            }
        }

        return buildResponse("404 Not Found", "method not implemented");
    }

    std::map<std::string, std::string> parseQueryParams(const std::string& url) {
        std::map<std::string, std::string> query_params;
        auto query_start = url.find('?');
        if (query_start == std::string::npos) {
            return query_params;
        }

        std::string query = url.substr(query_start + 1);
        std::regex query_regex("([^&=]+)=([^&]*)");
        auto query_begin = std::sregex_iterator(query.begin(), query.end(), query_regex);
        auto query_end = std::sregex_iterator();

        for (auto it = query_begin; it != query_end; ++it) {
            query_params[it->str(1)] = it->str(2);
        }

        return query_params;
    }

    std::string buildResponse(const std::string& status, const std::string& body) {
        std::ostringstream response;
        response << "HTTP/1.1 " << status << "\r\n";
        response << "Content-Length: " << body.size() << "\r\n";
        response << "Content-Type: text/plain\r\n";
        response << "\r\n";
        response << body;
        return response.str();
    }
};

int main() {
    SimpleHttpServer server(3000);
    server.start();
    return 0;
}