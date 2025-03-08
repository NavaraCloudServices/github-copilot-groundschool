package copilot.httpserver;

import static org.hamcrest.Matchers.equalTo;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import io.restassured.RestAssured;
import static io.restassured.RestAssured.given;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.DEFINED_PORT)
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