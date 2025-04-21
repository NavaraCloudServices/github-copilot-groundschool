BeforeAll {
    # Set the path to the Bicep template relative to this test file
    $templatePath = Join-Path -Path $PSScriptRoot -ChildPath "../main.bicep"
    
    # Verify the template file exists
    $templateExists = Test-Path -Path $templatePath
    
    # If template exists, try to get its content
    if ($templateExists) {
        $templateContent = Get-Content -Path $templatePath -Raw
    }
}

Describe "Bicep Template Validation" {
    Context "File Validation" {
        It "Template file should exist" {
            $templateExists | Should -Be $true
        }
    }
    
    Context "Syntax Validation" {
        It "Template should compile with az bicep build" {
            $compileResult = $null
            try {
                $compileResult = Invoke-Expression "az bicep build --file $templatePath --stdout" 2>&1
                $LASTEXITCODE | Should -Be 0
            }
            catch {
                Write-Error "Error compiling Bicep template: $_"
                $LASTEXITCODE | Should -Be 0
            }
        }
    }
    
}
