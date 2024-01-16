#ifndef CPP4_3DVIEWER_V2_0_1_PARSER_H_
#define CPP4_3DVIEWER_V2_0_1_PARSER_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../../common.h"

namespace s21 {
class VFParser {
 public:
  VFParser() = delete;
  VFParser(const VFParser &) = delete;
  VFParser(VFParser &&) = delete;
  VFParser operator=(const VFParser &) = delete;
  VFParser operator=(VFParser &&) = delete;

  static bool RecordDataFromFile(const std::string &file_path,
                                 s21::ObjectData &object_data);

 private:
  static void RecordVertex(std::istringstream &iss,
                           s21::ObjectData &object_data);
  static void RecordFacet(std::istringstream &iss,
                          s21::ObjectData &object_data);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_PARSER_H_
