package azure_tests

import (
	"testing"

	"github.com/gruntwork-io/terratest/modules/terraform"
	"github.com/stretchr/testify/assert"
)

func TestAzure(t *testing.T) {
    // Arrange
    expectedLocation := "westeurope"
    terraformOptions := terraform.WithDefaultRetryableErrors(t, &terraform.Options{
        // Set the path to the Terraform code
        TerraformDir: "../",

        // Environment variables to set when running Terraform
        EnvVars: map[string]string{
            "AZURE_DEFAULT_LOCATION": expectedLocation,
        },
    })

    // Use defer to ensure cleanup after test is complete
    defer terraform.Destroy(t, terraformOptions)

    // Act
    // This will run `terraform init` and `terraform apply`
    terraform.InitAndApply(t, terraformOptions)

    // Assert
    // Get the value of the region output
    actualLocation := terraform.Output(t, terraformOptions, "azure_location")
    
    // Verify that the region is set correctly
    assert.Equal(t, expectedLocation, actualLocation, "Azure location should match expected value")
}
