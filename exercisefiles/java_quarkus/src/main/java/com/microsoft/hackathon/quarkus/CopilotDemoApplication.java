package com.microsoft.hackathon.quarkus;

import jakarta.ws.rs.GET;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.MediaType;
import jakarta.annotation.PostConstruct;

// write a Java Quarkus server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

public class CopilotDemoApplication {
  
	public static void main(String[] args) {
        System.out.println("server is listening on port 3000");
    }

    @GET
    @Path("/get")
    @Produces(MediaType.TEXT_PLAIN)
    public String get(@QueryParam("key") String key) {
        System.out.println("server is listening on port 3000");
        if (key == null) {
            return "key not passed";
        }
        return "hello " + key;
    }
}

