import * as assert from 'assert';
import * as http from 'http';

describe('Node Server', () => {
    it('should return "key not passed" if key is not passed', (done: Mocha.Done) => {
        http.get('http://localhost:3000/get', (res: http.IncomingMessage) => {
            let data = '';
            res.on('data', (chunk: string) => {
                data += chunk;
            });
            res.on('end', () => {
                assert.strictEqual(data, 'key not passed');
                done();
            });
        });
    });
});
