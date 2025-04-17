// write a nodejs server in typescript that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"

import * as http from 'http';
import * as url from 'url';
import * as querystring from 'querystring';

const server = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url || '', true);
    const pathname = parsedUrl.pathname;
    const query = parsedUrl.query;

    if (pathname === '/hello') {
        const name = query.name;
        if (name) {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`hello ${name}`);
        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain' });
            res.end('name not passed');
        }
    } else {
        res.writeHead(501, { 'Content-Type': 'text/plain' });
        res.end('method not implemented');
    }
}