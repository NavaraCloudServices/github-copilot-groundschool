#!/bin/bash

# This script runs the Bicep template tests using PowerShell Core (pwsh) and Pester

# Check if PowerShell Core is installed
if ! command -v pwsh &> /dev/null; then
    echo "PowerShell Core (pwsh) is not installed. Please install it to run these tests."
    echo "You can install it with: https://learn.microsoft.com/en-us/powershell/scripting/install/installing-powershell-on-linux"
    exit 1
fi

# Check if the Azure CLI is installed
if ! command -v az &> /dev/null; then
    echo "Azure CLI is not installed. Please install it to run these tests."
    echo "You can install it with: https://docs.microsoft.com/en-us/cli/azure/install-azure-cli"
    exit 1
fi

# Check if Bicep is installed in Azure CLI
if ! az bicep version &> /dev/null; then
    echo "Bicep is not installed in Azure CLI. Installing now..."
    az bicep install
fi

# Check if the Pester module is installed in PowerShell
PESTER_INSTALLED=$(pwsh -Command "if (Get-Module -ListAvailable -Name Pester) { Write-Output 'true' } else { Write-Output 'false' }")

if [ "$PESTER_INSTALLED" != "true" ]; then
    echo "Installing Pester module for PowerShell..."
    pwsh -Command "Install-Module -Name Pester -Force -SkipPublisherCheck -Scope CurrentUser"
fi

# Run the Pester tests
echo "Running Bicep tests with Pester..."
pwsh -Command "Import-Module Pester; Invoke-Pester -Path './bicep_test.ps1' -Output Detailed"