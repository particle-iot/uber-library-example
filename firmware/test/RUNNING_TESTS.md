How to Run Tests
===

This page is a cruel trick; we're not sure what the best way to do [test driven embedded development](http://pragprog.com/book/jgade/test-driven-development-for-embedded-c) for Spark is. If you figure it out and can document it here, and illustrate it in the firmware/test folder, please issue a pull request. :).

Here's what we're currently thinking about TDD and Spark Libraries

The user of a library to be able to do:

    git clone the-library.git
    cd the-library/firmware/test
    make
    
And see a bunch of TAP test output like this:

    1..3
    ok 1 - it can have a pin set high
    # some comments about what is happening
    ....
    ok 2 - it can have a pin set low
    not ok 3 - it can modulate pin frequencyat 10ms 

The compiler would use standard GNU C++ build tools and stub out anything specific to the Spark firmware platform or ARM architecture.
