package aws_tests

import (
	"testing"

	"github.com/gruntwork-io/terratest/modules/terraform"
	"github.com/stretchr/testify/assert"
)

// TestAWS validates that our AWS Terraform code works as expected
func TestAWS(t *testing.T) {
    // Arrange
    expectedRegion := "eu-west-1"
    terraformOptions := terraform.WithDefaultRetryableErrors(t, &terraform.Options{
        // Set the path to the Terraform code
        TerraformDir: "../",

        // Environment variables to set when running Terraform
        EnvVars: map[string]string{
            "AWS_DEFAULT_REGION": expectedRegion,
        },
    })

    // Use defer to ensure cleanup after test is complete
    defer terraform.Destroy(t, terraformOptions)

    // Act
    // This will run `terraform init` and `terraform apply`
    terraform.InitAndApply(t, terraformOptions)

    // Assert
    // Get the value of the region output
    actualRegion := terraform.Output(t, terraformOptions, "aws_region")
    
    // Verify that the region is set correctly
    assert.Equal(t, expectedRegion, actualRegion, "AWS region should match expected value")
}
