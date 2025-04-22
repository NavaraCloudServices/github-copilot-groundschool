# Deploy a Node.js App on Kubernetes with GitHub Copilot

You need to deploy a simple web application on Kubernetes. The application is a simple Node.js app that returns "Hello World" when accessed.


## Part 1: Scaffold a Node.js App

Create a basic app.js file that:
- Runs an Express server
- Has a single route at / that returns "Hello, World"

## Part 2: Dockerize the App

Create a Dockerfile using GitHub Copilot.

It should:
- Use the node:22-alpine base image
- Copy the app code
- Install dependencies
- Expose port 3000
- Define the startup command

## Part 3: Write Kubernetes Manifests

Create the following Kubernetes YAML files
deployment.yaml
- Deploys the Node.js app with 2 replicas
- Container image from Docker Hub (e.g. yourusername/node-k8s-app)

service.yaml
- Exposes the deployment as a ClusterIP service on port 80 -> 3000

## Part 4: Expose via Ingress

Create an ingress.yaml that routes traffic to your service.
Use Copilot to suggest annotations and paths.

## Part 5: Bonus Challenge

Ask learners to modify the deployment to include:

- An environment variable (e.g. NODE_ENV=production)
- Resource limits