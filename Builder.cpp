//
// Created by physi on 31-05-2025.
//

#include "Builder.h"

std::string HTMLElement::str(int indent) const {
  std::ostringstream oss;
  std::string i(indent_size * indent, ' ');
  oss << i << '<' << name << '>' << std::endl;
  if (!text.empty()) {
    std::string i(indent_size * indent + 1, ' ');
    oss << i << text << std::endl;
  }
  for (auto obj : children) {
    std::string extra = obj.str(indent + 1);
    oss << extra;
  }
  oss << i << "</" << name << '>' << std::endl;
  return oss.str();
}

HTMLBuilder& HTMLBuilder::add_element(std::string name, std::string text) {
  root.children.push_back(HTMLElement(name, text));
  return *this;
}

std::string HTMLBuilder::str() const { return root.str(); }
HTMLBuilder::operator HTMLElement() const { return root; }
// HTMLElement HTMLBuilder::build() { return this->root; }
