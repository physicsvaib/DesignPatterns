#include <iostream>

#include "Factory.h"

int main() {
  Point c = Point::Factory.create_cartesian(10, 29);
  Point p = Point::Factory.create_polar(10, 29);

  std::cout << c << std::endl;
  std::cout << p << std::endl;
}
