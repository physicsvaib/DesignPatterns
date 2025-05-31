//
// Created by physi on 30-05-2025.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <string>
#include <utility>
#include <vector>


class KeyBoard {
public:
  KeyBoard(std::string color, std::string language, const int &keys) : color{std::move(color)},
                                                                       language{std::move(language)},
                                                                       keyCount{keys} {
  };


  std::string color;
  std::string language;
  int keyCount = 0;
};

template<typename T>
struct Specifications {
  virtual bool is_satified(T *item) = 0;
};

template<typename T>
struct Filter {
  virtual std::vector<T *> filter(std::vector<T *> objs, Specifications<T> &specs) = 0;
};

struct BetterFilter : Filter<KeyBoard> {
  std::vector<KeyBoard *> filter(std::vector<KeyBoard *> objs, Specifications<KeyBoard> &specs) override {
    {
      std::vector<KeyBoard *> results;
      for (const auto &obj: objs) {
        if (specs.is_satified(obj)) {
          results.push_back(obj);
        }
      }
      return results;
    }
  }
};

struct Search_By_Color : Specifications<KeyBoard> {
  Search_By_Color(std::string color) : color{std::move(color)} {
  };
  std::string color;

  bool is_satified(KeyBoard *item) override {
    return item->color == color;
  }
};

#endif //KEYBOARD_H
