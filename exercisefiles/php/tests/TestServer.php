
<?php

use PHPUnit\Framework\TestCase;

class TestServer extends TestCase
{
    private $baseUrl = "http://localhost:3000";

    // Function to send HTTP requests using cURL
    private function sendRequest($method, $endpoint, $queryParams = [])
    {
        $url = $this->baseUrl . $endpoint;
        if (!empty($queryParams)) {
            $url .= '?' . http_build_query($queryParams);
        }

        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);

        // Execute the request
        $response = curl_exec($ch);
        $err = curl_error($ch);
        curl_close($ch);

        if ($err) {
            return "cURL Error #: " . $err;
        } else {
            return $response;
        }
    }

    public function testGetWithKey()
    {
        $response = $this->sendRequest('GET', '/hello', ['name' => 'world']);
        $expected = "hello world";
        $this->assertEquals($expected, $response, "GET /hello with name=world should return 'hello world'");
    }

    public function testGetWithoutKey()
    {
        $response = $this->sendRequest('GET', '/hello');
        $expected = "key not passed";
        $this->assertEquals($expected, $response, "GET /hello without key should return 'name not passed'");
    }
}
?>