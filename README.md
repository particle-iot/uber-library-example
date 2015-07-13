About
===

This repo serves as the specfication for what constitutes a valid Spark firmware library and an actual example library you can use as a reference when writing your own libraries.

Particle Libraries can be used in the [Particle IDE](https://build.particle.io/build).
_Soon_ you'll also be able to use them with the [Particle CLI](https://github.com/spark/particle-cli) and when compiling firmware locally with [Particle firmware](https://github.com/spark/firmware).

## Table of Contents

This README describes how to create libraries as well as the Particle Library Spec.

The other files constitute the Particle Library itself:

  - file, class, and function [naming conventions](doc/firmware-code-conventions.md)
  - [example apps](examples) that illustrate library in action
  - recommended approaches for [test-driven embedded development](test/RUNNING_TESTS.md)
  - [metadata](particle.json) to set authors, license, official names

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

### 3. Edit the particle.json firmware .h and .cpp files

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

## The Particle Library Spec

A Particle firmware library consists of:

  - a GitHub REPO with a public clone url
  - a JSON manifest (`particle.json`) at the root of the repo
  - a bunch of files and directories at predictable locations (as illustrated here)

More specifically, the collection of files comprising a Particle Library include the following:

### Supporting Files

1. a `particle.json` meta data file at the root of the library dir, very similar to NPM's `package.json`. (required)
  1. The content of this file is validated via [this JSON Schema](https://www.spark.io/spark_library_schema_v1.json).

2. a `README.md` that should provide one or more of the following sections
  - _About_: An overview of the library; purpose, and description of dominant use cases.
  - _Example Usage_: A simple snippet of code that illustrates the coolest part about your library.
  - _Recommended Components_: Description and links to example components that can be used with the library.
  - _Circuit Diagram: A schematic and breadboard view of how to wire up components with the library.
  - _Learning Activities_: Proposed challenges to do more sophisticated things or hacks with the library.

3. a `doc` directory of diagrams or other supporting documentation linked to from the `README.md`

### Firmware

1. a `firmware` folder containing code that will compile and execute on a Particle device. This folder contains:
  1. A bunch of `.h`, `.cpp`, and `.c` files constituting the header and source code of the library.
    1. _The main library header file_, intended to be included by users
      1. MUST be named the same as the "name" key in the `particle.json` + a `.h` extension. So if `name` is `uber-library-example`, then there should be a `uber-library-example.h` file in this folder. Other `.h` files, can exist, but this is the only one that is required.
      2. SHOULD define a C++ style namespace in upper camel case style from the name (i.e. uber-library-example -> UberLibraryExample)
    2. _The main definition file_, providing the bulk of the libraries public facing functionality
      1. MUST be named like the header file, but with a `.cpp` extension. (uber-library-example.cpp)
      2. SHOULD encapsulate all code inside a C++ style namespace in upper camel case style (i.e. UberLibraryExample)
    3. Other optional `.h` files, when included in a user's app, will be available for inclusion in the Web IDE via `#include "uber-library-example/SOME_FILE_NAME.h"`.
    4. Other optional `.cpp` files will be compiled by the Web IDE when the library is included in an app (and use `arm-none-eabi-g++` to build).
    5. Other optional `.c` files will be compiled by the Web IDE when the library is included in an app (and use `arm-none-eabi-gcc` to build).
  2. An `examples` sub-folder containing one or more flashable example firmware `.ino` or `.cpp` applications.
    1. Each example file should be named descriptively and indicate what aspect of the library it illustrates. For example, a JSON library might have an example file like `parse-json-and-output-to-serial.cpp`.
  3. A `test` sub-folder containing any associated tests

## Contributing

This repo is meant to serve as a place to consolidate insights from conversations had about libraries on the [Particle community site](https://community.particle.io), GitHub, or elsewhere on the web. "Proposals" to change the spec are pull requests that both define the conventions in the README AND illustrate them in underlying code. If something doesn't seem right, start a community thread or issue pull requests to stir up the conversation about how it ought to be!
