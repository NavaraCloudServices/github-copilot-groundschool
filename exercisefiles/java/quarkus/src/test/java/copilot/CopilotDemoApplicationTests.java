package copilot;

import static org.hamcrest.Matchers.equalTo;
import org.junit.jupiter.api.Test;

import io.quarkus.test.junit.QuarkusTest;
import static io.restassured.RestAssured.given;

@QuarkusTest
class CopilotDemoApplicationTests {

    @Test
    void hello() {
        given()
            .queryParam("key", "world")
        .when()
            .get("/get")
        .then()
            .statusCode(200)
            .body(equalTo("hello world"));
    }
}