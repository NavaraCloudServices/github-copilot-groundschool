<?php


// write a nodejs server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

// Parse the request
$requestUri = $_SERVER['REQUEST_URI'];
$requestMethod = $_SERVER['REQUEST_METHOD'];

// Route handling
if ($requestMethod === 'GET') {
    $parsedUrl = parse_url($requestUri);
    if (isset($parsedUrl['path']) && $parsedUrl['path'] === '/get') {
        parse_str($parsedUrl['query'] ?? '', $queryParams);
        if (isset($queryParams['key']) && !empty($queryParams['key'])) {
            echo "hello " . htmlspecialchars($queryParams['key']);
            exit();
        } else {
            echo "key not passed";
            exit();
        }
    }
}

// Handle unsupported methods or endpoints
echo "method not supported";
?>

