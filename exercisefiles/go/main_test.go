package main

import (
	"net/http"
	"net/http/httptest"
	"testing"
	. "gopkg.in/check.v1"
)

// Hook up gocheck into the "go test" runner.
func Test(t *testing.T) { TestingT(t) }

type MainSuite struct{}

var _ = Suite(&MainSuite{})

func (s *MainSuite) TestGetHandlerWithoutName(c *C) {
	req, err := http.NewRequest("GET", "/hello", nil)
	c.Assert(err, IsNil)

	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(getHandler)
	handler.ServeHTTP(rr, req)

	c.Assert(rr.Body.String(), Equals, "name not passed\n")
}
