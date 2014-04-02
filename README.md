uber-library-example
====================

The canonical Spark firmware library; exemplifies meta-data, class, file naming conventions, etc.
This repo exists to demonstrate how to structure a Spark library. 
WARNING: This is currently under active development. 

## What is a Spark Library?

A Spark firmware library consists of:

  - a Git REPO with a clone url
  - a JSON manifest (`spark.json`)
  - a bunch of files and directories at predictable locations

Most specifically, the collection of files comprising a Spark Library include the following:

- a `spark.json` meta data file at the root of the library dir, very similar to NPM's `package.json`. (required)

- a `firmware` folder containing code that will compile and execute on a Spark devce. This folder contains
  - An `inc` folder with one or more `.h` files
  - A `src` folder with one or more `.ino` or `.cpp` files
  - An `examples` folder containing one or more flashable example firmware `.ino` or `.cpp` applications
  - A `test` folder containing any associated tests

- a `README.md` that should include 
  - some instructions on how to install and use the library
  - a recommended bill of materials
  - instructions on how to wire up a circuits that will work with the flashable example firmware that ship with the library

- a `doc` directory of Fritzing diagrams or other supporting documentation linked to from the `README.md`
