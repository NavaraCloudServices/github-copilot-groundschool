variable "aws_region" {
    description = "AWS provider configuration"
    type        = object({
        region = string
    })
    default = {
        region = "eu-west-1"
    }
}