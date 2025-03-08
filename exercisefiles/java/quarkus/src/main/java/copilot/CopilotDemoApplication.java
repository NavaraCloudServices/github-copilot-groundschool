package copilot;

import jakarta.ws.rs.Path;

// write a Java Quarkus server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

@Path("")
public class CopilotDemoApplication {

    public static void main(String[] args) {
        io.quarkus.runtime.Quarkus.run(args);
    }
}

