//
// Created by physi on 01-06-2025.
//

#include "Factory.h"

#include <cmath>
#include <sstream>
Point Point::PointFactory::create_cartesian(float x, float y) { return {x, y}; }

Point Point::PointFactory::create_polar(float rho, float theta) {
  return {static_cast<float>(rho * cos(theta)),
          static_cast<float>(rho * sin(theta))};
}

std::string Point::to_string() const {
  std::ostringstream os;
  os << this->get_x() << " " << this->get_y() << std::endl;
  return os.str();
}