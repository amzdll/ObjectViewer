#include "v_f_parser.h"

bool s21::VFParser::RecordDataFromFile(const std::string &file_path,
                                       s21::ObjectData &object_data) {
  std::ifstream input_file(file_path);
  if (!input_file.is_open()) {
    return false;
  }

  std::ios::sync_with_stdio(false);
  object_data.facets.clear();
  object_data.vertices.clear();
  std::string line;
  while (std::getline(input_file, line)) {
    std::istringstream iss(line);
    std::string data_type;
    iss >> data_type;
    if (data_type == "v") {
      RecordVertex(iss, object_data);
    } else if (data_type == "f" && !object_data.vertices.empty()) {
      RecordFacet(iss, object_data);
    }
  }
  input_file.close();
  return true;
}

void s21::VFParser::RecordVertex(std::istringstream &iss,
                                 s21::ObjectData &object_data) {
  s21::Coordinates vertex{};
  iss >> vertex.x >> vertex.y >> vertex.z;
  object_data.vertices.push_back(vertex);
}

void s21::VFParser::RecordFacet(std::istringstream &iss,
                                s21::ObjectData &object_data) {
  int facet_value;
  std::string facet_string;
  std::vector<unsigned int> source_facets;
  while (iss >> facet_string) {
    std::istringstream facet_iss(facet_string);
    std::string facet_data;
    std::getline(facet_iss, facet_data, '/');
    if (facet_string.find_first_not_of("-f/0123456789") != std::string::npos) {
      return;
    }
    facet_value = std::stoi(facet_data) - 1;
    if (facet_value < 0) {
      facet_value =
          static_cast<int>(object_data.vertices.size()) + facet_value + 1;
    }
    source_facets.push_back(facet_value);
  }

  object_data.facets.push_back(source_facets[0]);
  for (size_t i = 1; i < source_facets.size(); ++i) {
    object_data.facets.push_back(source_facets[i]);
    object_data.facets.push_back(source_facets[i]);
  }
  object_data.facets.push_back(source_facets[0]);
}
