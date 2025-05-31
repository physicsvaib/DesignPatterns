#include <iostream>
#include "KeyBoard.h"

int main() {
    auto k1 = KeyBoard("red", "eng", 108);
    auto k2 = KeyBoard("red", "hin", 108);
    auto k3 = KeyBoard("red", "kor", 108);
    auto k4 = KeyBoard("green", "kor", 108);

    std::vector<KeyBoard *> keyboards{&k1, &k2, &k3, &k4};

    Search_By_Color specs = Search_By_Color("red");
    BetterFilter filter;


    for (const auto &i: filter.filter(keyboards, specs)) {
        std::cout << i->language << std::endl;
    }
}
