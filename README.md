# ptc::tuple

    ptc::tuple<int, std::string, float> myTuple(1, "Hello, World!", -4.0f);
    int foo = ptc::get<0>(myTuple);
    std::string bar = ptc::get<1>(myTuple);
    float baz = ptc::get<2>(myTuple);
    printf("%d %s %.1f\n", foo, bar.c_str(), baz);

## Reimplementing std::tuple For No Good Reason

std::tuple uses some fun C++11 variadic templates, along with a clever design
to allow tuples in C++11, which is pretty cool. It's also a terrible hack.

### Advanced Build and Usage Guide

    $ clang++ -std=c++11 tuple_use.cpp -o tuple_use
    $ ./tuple_use
    1 Hello, World! -4.0
    $ echo "Wow, what tuple, such variadic, very dated meme"
