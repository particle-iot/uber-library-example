About
===

This repo serves as 1) the definitive spec for what constitutes a Spark firmware library as well as 2) an actual example library you can use as a reference when writing your own libraries, running locally, or include in the Web IDE.

- This README describes the Spark Library spec.

- The other files constitute the Spark Library itself.

This repo is meant to serve as a place to consolidate insights from conversations had about libraries on the [Spark community site](https://community.spark.io), GitHub, or elsewhere on the web. "Proposals" to change the spec are pull requests that both define the conventions in the README AND illustrate them in underlying code. If something doesn't seem right, start a community thread or issue pull requests to stir up the conversation about how it ought to be!

_What does the actual library do?_

Not much, :)...other than illustrate Spark library conventions in action.

- Illustrates an object oriented approach to encapsulating a Pin; instantiating, initializing, setting and getting state.
- Illustrates a functional approach to interacting with a pin.

## Example Usage

### Light up an LED when you tap the mode button.

The object oriented approach: See firmware/examples/set-d7-pin-high-when-mode-button-pressed.cpp

The functional approach: TODO

## A Spark firmware library consists of:

  - a Git REPO with a public clone url
  - a JSON manifest (`spark.json`)
  - a bunch of files and directories at predictable locations (as illustrated here)

More specifically, the collection of files comprising a Spark Library include the following:

### Firmware Code Conventions

In general or where unspecified, use node.js + [npm](https://www.npmjs.org/doc/misc/npm-coding-style.html) for inspiration while respecting the pragmatic realities of embedded programming.  Specifically:

- Use `all-lower-hyphen-css-case` for multiword filenames.
- Use `UpperCamelCase` for class names (things that you'd pass to "new") and namespaces
- Use `lowerCamelCase` for multiword identifiers when they refer to objects, functions, methods, members, or anything not specified in this section.
- Use `CAPS_SNAKE_CASE` for constants, things that should never change and are rarely used.

When using an acronym like `LED` or `JSON` in a class name, file name, or other context above, don't necessarily use all caps.  Instead, let the convention drive the spelling. For example, a class that blinks LEDs would be called `LedBlinker`, and live in a file called `led-blinker.cpp`

- Use two spaces for indentation.
- Prefix variables or functions with an underscore (`_`) when indended for very narrow, restricted, local usage.
- Functions or methods that begin with the name `begin`, are meant to be called in the `setup()` function.
- Curly Brackets should go on the next line after a class or function definition like this:

    void my_killer_function()
    {

    }

### Files & Folders

- a `spark.json` meta data file at the root of the library dir, very similar to NPM's `package.json`. (required)

- a `firmware` folder containing code that will compile and execute on a Spark devce. This folder contains
  - An `inc` folder with one or more `.h` files.
    - One of the files MUST be named the same as the "name" key in the `spark.json` with a `.h` added. So if `name` is `uber-library-example`, then there should be a `uber-library-example.h` file in this folder.
  - A `src` folder with one or more `.ino` or `.cpp` files.
    - The main definition file of the library, where the dominant class users will use in their code or functions are defined, MUST be named the same as the "name" key in the `spark.json`. For example `uber-library-example.cpp` would be a valid main definition file. There can only be ONE main definition file, i.e. you CANNOT have both a `uber-library-example.cpp` AND `uber-library.example.ino`.
  - An `examples` folder containing one or more flashable example firmware `.ino` or `.cpp` applications.
    - Each example file should be named descriptively and indicate what aspect of the library it illustrates. For example, a JSON library might have an example file like `parse-json-and-output-to-serial.cpp`.
  - A `test` folder containing any associated tests
    - TODO: Someone who has strong opinions about [test driven embedded development](http://pragprog.com/book/jgade/test-driven-development-for-embedded-c), should issue a pull request to spec this :).
- a good `README.md` will provide one or more of the following sections
  - _About_: An overview of the library; purpose, and description of dominant use cases.
  - _Example Usage_: A simple snippet of code that illustrates the coolest part about your library.
  - _Recommended Components_: Description and links to example components that can be used with the library.
  - _Circuit Diagram: A schematic and breadboard view of how to wire up components with the library.
  - _Learning Activities_: Proposed challenges to do more sophisticated things or hacks with the library.

- a `doc` directory of diagrams or other supporting documentation linked to from the `README.md`
