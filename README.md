uber-library-example
====================

_Why?_

The canonical Spark firmware library; exemplifies meta-data, class, file naming conventions, etc.  This repo mainly exists to demonstrate how to structure a Spark library that can be reused in other projects and imported into the Web IDE...under active development...

_What?_

Blinks the D7 LED when you top the mode button.

## What is a Spark Library?

A Spark firmware library consists of:

  - a Git REPO with a clone url
  - a JSON manifest (`spark.json`)
  - a bunch of files and directories at predictable locations (as illustrated here)

More specifically, the collection of files comprising a Spark Library include the following:

### Some opinions about naming

In general, use [npm](https://www.npmjs.org/doc/misc/npm-coding-style.html) for inspiration.

Specifically:

- Use `all-lower-hyphen-css-case` for multiword filenames.
- Use `UpperCamelCase` for class names (things that you'd pass to "new").
- Use `CAPS_SNAKE_CASE` for constants, things that should never change and are rarely used.

### Files & Folders

- a `spark.json` meta data file at the root of the library dir, very similar to NPM's `package.json`. (required)

- a `firmware` folder containing code that will compile and execute on a Spark devce. This folder contains
  - An `inc` folder with zero or more `.h` files.
    - If one or more is specified, one of the files MUST be named the same as the "name" key in the `spark.json` with a `.h` added. So if `name` is `uber-library-example`, then there should be a `uber-library-example.h` file in this folder.
  - A `src` folder with one or more `.ino` or `.cpp` files.
    - The main definition file of the library, where the dominant class users will use in their code or functions are defined, MUST be named the same as the "name" key in the `spark.json`. For example `uber-library-example.cpp` would be a valid main definition file.
  - An `examples` folder containing one or more flashable example firmware `.ino` or `.cpp` applications.
    - Each example file should be named descriptively and indicate what aspect of the library it illustrates. For example, a JSON library might have an example file like `parse-json-and-output-to-serial.cpp`.
  - A `test` folder containing any associated tests
    - TODO: Someone who has strong opinions about [test driven embedded development](http://pragprog.com/book/jgade/test-driven-development-for-embedded-c), should issue a pull request to spec this :).
- a `README.md` that should include 
  - some instructions on how to install and use the library
  - a recommended bill of materials
  - instructions on how to wire up a circuits that will work with the flashable example firmware that ship with the library

- a `doc` directory of Fritzing diagrams or other supporting documentation linked to from the `README.md`

### Code

Let's start with some code that illustrates the simpliest thing that could be called a library

In `inc/uber-library-example.h` (the "main definition header"), you'll see something like this (see `//` prefaced code for annotations.).

    // Boilerplate, ignore or google it
    #ifndef _UBER_LIBRARY_EXAMPLE
    #define _UBER_LIBRARY_EXAMPLE

    // Constants
    #define UBER_LIBRARY_CONST1 42

    // Includes
    #include "uber-helper-thing.h"

    /*
    * Highlevel Documentation
    */

    class UberLibraryExample {
    public:
      // Constructor
      UberLibraryExample();

      // `setup()` methods, that users should call in their `setup()` function
      void begin();

      // Methods for manipulating instances of the class
      bool getPacketReceivedCount();
      void resetPacketReceivedCount();

    // Tuck methods you don't want the user of your library into
    // `private` scope
    private:
      char _serverName[SPARKTIMEHOSTNAMESIZE];
      bool _syncedOnce = false;
      bool _isSyncing = false;
    };

    #endif

For the most common use case of your library, users should be able to simply do `#include "uber-library-example.h"` to start using your library.

A simple flashable application firmware might look like this:

    #include "uber-library-example.h"`

    // Allocate global vars
    UberLibraryExample uberLibraryExample;
    unsigned long int currentTime;

    def setup()
      // Call initialization routines
      uberLibraryExample.begin();
    end

    def loop()
      // Use the library
      uberLibraryExample = UberLibraryExample();
    end

