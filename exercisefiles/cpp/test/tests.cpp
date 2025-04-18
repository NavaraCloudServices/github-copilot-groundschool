#include <gtest/gtest.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <iostream>

TEST(ServerTest, NameNotPassedTest) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT_GE(sock, 0) << "Could not create socket";

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int conn = connect(sock, (struct sockaddr*)&server, sizeof(server));
    ASSERT_GE(conn, 0) << "Connection to server failed";

    std::string request = "GET /hello HTTP/1.1\r\nHost: localhost\r\n\r\n";
    send(sock, request.c_str(), request.size(), 0);

    char buffer[1024];
    int received = read(sock, buffer, 1024);
    ASSERT_GE(received, 0) << "Failed to read response";

    std::string response(buffer, received);
    close(sock);

    // Validate "key not passed"
    EXPECT_NE(std::string::npos, response.find("name not passed")) 
        << "Expected response to contain 'name not passed'";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}