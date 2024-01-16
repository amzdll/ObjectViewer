#include "object_facade.h"

namespace s21 {

bool ObjectFacade::RecordData(const std::string& file_path) {
  return StrategyRecorder<VFParser>::RecordDataFromFile(file_path,
                                                        object_data_);
}

void ObjectFacade::SearchingMarginalCooridnates() {
  float min_x_ = 0;
  float max_x_ = 0;
  float min_y_ = 0;
  float max_y_ = 0;
  float min_z_ = 0;
  float max_z_ = 0;
  if (!object_data_.vertices.empty()) {
    min_x_ = object_data_.vertices[0].x;
    max_x_ = object_data_.vertices[0].x;
    min_y_ = object_data_.vertices[0].y;
    max_y_ = object_data_.vertices[0].y;
    min_z_ = object_data_.vertices[0].z;
    max_z_ = object_data_.vertices[0].z;
  }

  for (const auto& vertex : object_data_.vertices) {
    min_x_ = std::min(min_x_, vertex.x);
    max_x_ = std::max(max_x_, vertex.x);
    min_y_ = std::min(min_y_, vertex.y);
    max_y_ = std::max(max_y_, vertex.y);
    min_z_ = std::min(min_z_, vertex.z);
    max_z_ = std::max(max_z_, vertex.z);
  }

  scene_parameters_["scene_size"] =
      std::max({max_x_ - min_x_, max_y_ - min_y_, max_z_ - min_z_});
  scene_parameters_["center_x"] = (min_x_ + max_x_) / 2;
  scene_parameters_["center_y"] = (min_y_ + max_y_) / 2;
  scene_parameters_["center_z"] = (min_z_ + max_z_) / 2;
}

s21::ObjectData ObjectFacade::GetObjectData() { return object_data_; };

double ObjectFacade::GetScale() { return scale_; }

std::vector<Coordinates> ObjectFacade::GetCoordinates() { return coordinates_; }

std::vector<Coordinates> ObjectFacade::GetAngles() { return angles_; }

std::map<std::string, float> ObjectFacade::GetSceneParameters() {
  SearchingMarginalCooridnates();
  return scene_parameters_;
}

void ObjectFacade::SetScale(double scale) { scale_ = scale; }

void ObjectFacade::SetAngles(std::vector<Coordinates> angles) {
  angles_ = angles;
}

void ObjectFacade::SetCoordinates(std::vector<Coordinates> coordinates) {
  coordinates_ = coordinates;
}
}  // namespace s21