import static org.hamcrest.Matchers.equalTo;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import copilot.CopilotDemoApplication;
import io.restassured.RestAssured;
import static io.restassured.RestAssured.given;

@SpringBootTest(
    webEnvironment = SpringBootTest.WebEnvironment.DEFINED_PORT,
    classes = CopilotDemoApplication.class // Specify the main application class
)
class CopilotDemoApplicationTests {

    @Test
    void hello() {
        RestAssured.port = 3000; // Set the port if different from default

        given()
            .queryParam("name", "world")
        .when()
            .get("/hello")
        .then()
            .statusCode(200)
            .body(equalTo("hello world"));
    }
}