package com.microsoft.hackathon.copilotdemo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;


// write a Java Spring Boot server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

@SpringBootApplication
public class CopilotDemoApplication {

    public static void main(String[] args) {
        SpringApplication.run(CopilotDemoApplication.class, args);
    }
}