package copilot;

// write a java sprintboot http server that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"


import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RestController;


@SpringBootApplication
@RestController
public class CopilotDemoApplication {

    public static void main(String[] args) {

    }
}