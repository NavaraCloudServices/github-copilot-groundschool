variable "azure_location" {
  description = "Azure provider configuration"
  type = object({
    location = string
  })
  default = {
    location = "westeurope"
  }
}
