How to Run Tests
===

We're currently not sure what the best way to do [test driven embedded development](http://pragprog.com/book/jgade/test-driven-development-for-embedded-c) for Spark is.  Here's what we know about how a Spark library should be unit tested:

- Unit tests should run a regular computer, not a Spark Core
- A developer should be able to cd into `firmware/test` and type `make` to run the unit tests.
- The tests should stub out Spark specific functionality so the code compiles and runs using on a
  standard GNU C++ compiler.
- When the compiled binary is run, it should print test output using the [Test Anything Protocol](http://en.wikipedia.org/wiki/Test_Anything_Protocol). i.e. "ok" for test pass and "not ok" for test failure.
- When any test fails, the binary should return a non-zero exit code.


How to help out
---

If you have ideas about how to do this, please start a conversation at [community.spark.io](http://community.spark.io), or fork this repository and issue a pull request that illustrates how to do unit testing of this Spark library.
