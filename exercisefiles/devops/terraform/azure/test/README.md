# Terraform AWS Tests

This directory contains tests for the AWS Terraform infrastructure code.

## Prerequisites

- [Go](https://golang.org/doc/install) (v1.16 or later)
- [Terratest](https://github.com/gruntwork-io/terratest)

## Setup

1. Install Go dependencies:
   ```bash
   go mod tidy
   ```

## Running Tests

Execute all tests:
```bash
go test -v ./...
```

Run a specific test:
```bash
go test -v -run TestAzure
```