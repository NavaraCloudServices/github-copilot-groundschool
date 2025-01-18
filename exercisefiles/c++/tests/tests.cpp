#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Could not create socket\n";
        return 1;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connection to server failed\n";
        close(sock);
        return 1;
    }

    // Send GET request without key
    std::string request = "GET /get HTTP/1.1\r\nHost: localhost\r\n\r\n";
    send(sock, request.c_str(), request.size(), 0);

    char buffer[1024];
    int received = read(sock, buffer, 1024);
    if (received < 0) {
        std::cerr << "Failed to read response\n";
        close(sock);
        return 1;
    }

    std::string response(buffer, received);
    close(sock);

    // Check if response contains "key not passed"
    if (response.find("key not passed") != std::string::npos) {
        std::cout << "[PASS] Key not passed test succeeded\n";
    } else {
        std::cout << "[FAIL] Key not passed test did not return expected response\n";
        return 1;
    }

    return 0;
}