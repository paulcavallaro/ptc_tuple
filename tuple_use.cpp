#include "tuple.hpp"

#include <string>

int main(int argc, char** argv) {
  ptc::tuple<int, std::string, float> myTuple(1, "Hello, World!", -4.0f);
  int foo = ptc::get<0>(myTuple);
  std::string bar = ptc::get<1>(myTuple);
  float baz = ptc::get<2>(myTuple);
  printf("%d %s %.1f\n", foo, bar.c_str(), baz);
};
