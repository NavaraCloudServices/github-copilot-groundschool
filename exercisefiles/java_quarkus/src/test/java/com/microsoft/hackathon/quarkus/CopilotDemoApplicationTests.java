package com.microsoft.hackathon.quarkus;


import static org.hamcrest.Matchers.equalTo;
import org.junit.jupiter.api.Test;

import io.quarkus.test.junit.QuarkusTest;
import io.restassured.RestAssured;
import static io.restassured.RestAssured.given;

@QuarkusTest
class CopilotDemoApplicationTests {

    @Test
    void hello() {
        RestAssured.port = 3000; // Set the port if different from default

        given()
            .queryParam("key", "world")
        .when()
            .get("/get")
        .then()
            .statusCode(200)
            .body(equalTo("hello world"));
    }
}