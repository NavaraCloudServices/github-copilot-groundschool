# Bicep Template Tests

This directory contains tests for the Bicep templates in the parent directory.

## Test Structure

- `bicep_test.ps1`: Pester tests for validating Bicep templates
- `bicep_template_tests.psd1`: Configuration file for Bicep template tests
- `run_tests.sh`: Shell script to run the tests in Linux environments

## Running Tests

### On Windows

```powershell
Import-Module Pester
Invoke-Pester -Path ./bicep_test.ps1
```

### On Linux/macOS

```bash
chmod +x run_tests.sh
./run_tests.sh
```

## Test Coverage

The tests validate:

- Template compilation
- Parameter validation
- Resource properties and configurations