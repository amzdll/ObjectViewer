#ifndef CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_
#define CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_

#include "Recorder/V_F_Recorder/v_f_parser.h"
#include "Recorder/strategy_recorder.h"
#include "common.h"

namespace s21 {
class ObjectFacade {
 public:
  // main logic
  bool RecordData(const std::string& file_path);
  void SearchingMarginalCooridnates();

  // getters and setters
  s21::ObjectData GetObjectData();
  double GetScale();
  std::vector<Coordinates> GetCoordinates();
  std::vector<Coordinates> GetAngles();
  std::map<std::string, float> GetSceneParameters();

  void SetScale(double scale);
  void SetAngles(std::vector<Coordinates> angles);
  void SetCoordinates(std::vector<Coordinates> coordinates);

 private:
  std::map<std::string, float> scene_parameters_{
      std::pair<std::string, float>("scene_size", 0),
      std::pair<std::string, float>("center_x", 0),
      std::pair<std::string, float>("center_y", 0),
      std::pair<std::string, float>("center_z", 0)};

  double scale_ = 1;
  std::vector<Coordinates> coordinates_{{0, 0, 0}};
  std::vector<Coordinates> angles_{{0, 0, 0}};

  s21::ObjectData object_data_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_
