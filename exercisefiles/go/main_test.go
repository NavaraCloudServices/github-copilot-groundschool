package main

import (
	"net/http"
	"net/http/httptest"
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestGetHandlerWithoutName(t *testing.T) {
	req, err := http.NewRequest("GET", "/hello", nil)
	if err != nil {
		t.Fatal(err)
	}

	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(getHandler)
	handler.ServeHTTP(rr, req)

	assert.Equal(t, "name not passed", rr.Body.String(), "handler returned unexpected body")
}