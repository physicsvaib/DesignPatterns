//
// Created by physi on 31-05-2025.
//

#ifndef BUILDER_H
#define BUILDER_H
#include <sstream>
#include <vector>

// So whats the idea
// Actually its simple, Instead of having lets say 10 arguments in constructor
// why dont we just break it, introducing piece wise construction of an object.
// to provide a good API for creation of object with large parameters.

// Techniques to make that idea work may vary but the idea is simple
// theme is piece wise parameter passing and than building the object as
// specified by user mostly immutable objects so when we say build or construct
// a complex class after using builder we get the object with said params

struct HTMLElement {
 private:
  std::string name, text;
  std::vector<HTMLElement> children;
  const int indent_size = 2;
  friend class HTMLBuilder;
  HTMLElement(std::string name, std::string text) : name{name}, text{text} {}
  HTMLElement() {}

 public:
  std::string str(int indent = 0) const;
};

struct HTMLBuilder {
 private:
  HTMLElement root;

 public:
  HTMLBuilder(std::string head) { root.name = head; }
  HTMLBuilder& add_element(std::string name, std::string text);
  std::string str() const;

  operator HTMLElement() const;
  // HTMLElement build();
};

#endif  // BUILDER_H
