// write a c++ server that will expose a method call "hello" that will return the value of the name passed in the query string
// example: http://localhost:3000/hello?name=world
// if the name is not passed, return "name not passed"
// if the name is passed, return "hello " + key
// if the url has other methods, return "method not implemented"
// when server is listening, log "server is listening on port 3000"
// Use modern c++17 features
// favor compile-time features over runtime features
// Use c++ standard library only, no third party libraries
// Use design patterns where appropriate
// Do not use asio

#include <iostream>