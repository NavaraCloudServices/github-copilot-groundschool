// write a nodejs server that will expose a method call "get" that will return the value of the key passed in the query string
// example: http://localhost:3000/get?key=hello
// if the key is not passed, return "key not passed"
// if the key is passed, return "hello" + key
// if the url has other methods, return "method not supported"
// when server is listening, log "server is listening on port 3000"

import http from 'http';
import url from 'url';

const server = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url || '', true);
    const path = parsedUrl.pathname;
    
    // Set CORS headers
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Content-Type', 'text/plain');

    // Handle GET method for /get endpoint
    if (path === '/get') {
        const key = parsedUrl.query.key;
        
        if (!key) {
            res.writeHead(400);
            res.end('key not passed');
            return;
        }

        res.writeHead(200);
        res.end('hello ' + key);
        return;
    }

    // Handle unsupported methods/paths
    res.writeHead(405);
    res.end('method not supported');
});

const PORT = 3000;
server.listen(PORT, () => {
    console.log(`server is listening on port ${PORT}`);
});