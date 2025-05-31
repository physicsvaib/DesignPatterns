#include <iostream>

#include "Builder.h"
#include "KeyBoard.h"

int main() {
  auto k1 = KeyBoard("red", "eng", 108);
  auto k2 = KeyBoard("red", "hin", 108);
  auto k3 = KeyBoard("red", "kor", 108);
  auto k4 = KeyBoard("green", "kor", 108);

  std::vector<KeyBoard *> keyboards{&k1, &k2, &k3, &k4};

  Search_By_Color specs = Search_By_Color("red");
  BetterFilter filter;

  HTMLElement h1 = HTMLBuilder("h1")
                       .add_element("p", "this is a para")
                       .add_element("p", "this is another para");
  std::cout << h1.str() << std::endl;

  for (const auto &i : filter.filter(keyboards, specs)) {
    std::cout << i->language << std::endl;
  }
}
