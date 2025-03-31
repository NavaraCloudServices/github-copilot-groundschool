import * as assert from 'assert';
import * as http from 'http';

describe('Node Server', () => {
    it('should return "name not passed" if name is not passed', (done: Mocha.Done) => {
        http.get('http://localhost:3000/hello', (res: http.IncomingMessage) => {
            let data = '';
            res.on('data', (chunk: string) => {
                data += chunk;
            });
            res.on('end', () => {
                assert.strictEqual(data, 'name not passed');
                done();
            });
        });
    });
});
