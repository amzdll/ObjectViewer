#ifndef CPP4_3DVIEWER_V2_0_1_COMMON_H_
#define CPP4_3DVIEWER_V2_0_1_COMMON_H_

#include <map>
#include <vector>

namespace s21 {

struct Coordinates {
  Coordinates() = default;
  Coordinates(float x, float y, float z) : x(x), y(y), z(z){};
  float x, y, z;
};

struct ObjectData {
  std::vector<unsigned int> facets;
  std::vector<Coordinates> vertices;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_COMMON_H_
