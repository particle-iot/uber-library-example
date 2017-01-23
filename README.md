About
===

This repo serves as the specification for what constitutes a valid Spark firmware library and an actual example library you can use as a reference when writing your own libraries.

Particle Libraries can be used in the [Particle IDE](https://build.particle.io/build).
_Soon_ you'll also be able to use them with the [Particle CLI](https://github.com/spark/particle-cli) and when compiling firmware locally with [Particle firmware](https://github.com/spark/firmware).

## Table of Contents

This README describes how to create libraries as well as the Particle Library Spec.

The other files constitute the Particle Library itself:

  - file, class, and function [naming conventions](doc/firmware-code-conventions.md)
  - [example apps](examples) that illustrate library in action
  - recommended approaches for [test-driven embedded development](test/RUNNING_TESTS.md)
  - [metadata](library.properties) to set authors, license, official names

## Getting Started

### 1. Install Particle CLI

```
$ npm install -g particle-cli
```

### 2. Init new library

```
$ particle library init this-is-my-library-name
```

- Replace `this-is-my-library-name` with the actual lib name. Your library's name should be lower-case, dash-separated.

### 3. Edit the `library.properties`, firmware .h and .cpp files

- Use this repo as your guide to good library conventions.

### 4. Create a GitHub repo and push to it

### 5. Validate and publish

```
$ particle library validate
```

and

```
$ particle library publish
```

## Getting Support

- Check out the [libraries category on the Particle community site](https://community.particle.io/category/libraries) and post a thread there!
- To file a bug; create a GitHub issue on this repo. Be sure to include details about how to replicate it.

## Contributing

This repo is meant to serve as a place to consolidate insights from conversations had about libraries on the [Particle community site](https://community.particle.io), GitHub, or elsewhere on the web. "Proposals" to change the spec are pull requests that both define the conventions in the README AND illustrate them in underlying code. If something doesn't seem right, start a community thread or issue pull requests to stir up the conversation about how it ought to be!
