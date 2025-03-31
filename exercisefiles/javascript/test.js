const assert = require('assert');
const http = require('http');
const server = require('./nodeserver');

describe('Node Server', () => {
    it('should return "name not passed" if name is not passed', (done) => {
        http
        .get('http://localhost:3000/hello' , (res) => {
            let data = '';
            res.on('data', (chunk) => {
                data += chunk;
            });
            res.on('end', () => {
                assert.equal(data, 'name not passed');
                done();
            });
        });
    });
});
