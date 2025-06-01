//
// Created by physi on 01-06-2025.
//

#ifndef FACTORY_H
#define FACTORY_H
#include <ostream>
#include <string>

// the idea is
// to create a wholesale construction of object
// without the hassle of long or optional parameters of a class
// maybe sometimes we want to create multiple objects out of a class eg. point
// could be cartesian or polar coordinated since we dont have the luxury of
// creating 2 constructers enums seems to be a way out but again extra things
// could pile up

// Inner Factory
class Point {
 private:
  float x, y;
  Point(float x, float y) : x(x), y(y) {}

  struct PointFactory {
    PointFactory();
    static Point create_cartesian(float x, float y);
    static Point create_polar(float rho, float theta);
  };

 public:
  static PointFactory Factory;
  void set_x(float x) { this->x = x; }
  void set_y(float y) { this->y = y; }

  [[nodiscard]] float get_x() const { return x; }
  [[nodiscard]] float get_y() const { return y; }

  friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
    return os << "x: " << obj.x << " y: " << obj.y;
  }
  std::string to_string() const;
};

#endif  // FACTORY_H
