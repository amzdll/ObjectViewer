#include "object_controller.h"

namespace s21 {
ObjectHandlerController::ObjectHandlerController(
    s21::ObjectFacade *object_model_)
    : object_model_(object_model_){};

bool ObjectHandlerController::RecordDataFromFile(std::string file_path) {
  return object_model_->RecordData(file_path);
}

s21::ObjectData ObjectHandlerController::GetData() {
  return object_model_->GetObjectData();
};

double ObjectHandlerController::GetScale() { return object_model_->GetScale(); }

std::vector<Coordinates> ObjectHandlerController::GetCoordinates() {
  return object_model_->GetCoordinates();
}

std::vector<Coordinates> ObjectHandlerController::GetAngles() {
  return object_model_->GetAngles();
}

std::map<std::string, float> ObjectHandlerController::GetSceneParameters() {
  return object_model_->GetSceneParameters();
}

void ObjectHandlerController::SetScale(double scale) {
  object_model_->SetScale(scale);
}

void ObjectHandlerController::SetAngles(std::vector<Coordinates> angles) {
  object_model_->SetAngles(angles);
}
void ObjectHandlerController::SetCoordinates(
    std::vector<Coordinates> coordinates) {
  object_model_->SetCoordinates(coordinates);
}
}  // namespace s21