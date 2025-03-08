package copilot.httpserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

// write a java springboot that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"

@SpringBootApplication
public class CopilotDemoApplication {

    public static void main(String[] args) {
        SpringApplication.run(CopilotDemoApplication.class, args);
    }
}