#ifndef VIEWER_STRATEGYRECORDER_H
#define VIEWER_STRATEGYRECORDER_H

#include "../common.h"

namespace s21 {
template <class Recorder>
class StrategyRecorder {
 public:
  StrategyRecorder() = delete;
  StrategyRecorder(const VFParser &) = delete;
  StrategyRecorder(VFParser &&) = delete;
  StrategyRecorder operator=(const VFParser &) = delete;
  StrategyRecorder operator=(VFParser &&) = delete;

  static bool RecordDataFromFile(const std::string &file_path,
                                 s21::ObjectData &object_data) {
    return Recorder::RecordDataFromFile(file_path, object_data);
  };
};
}  // namespace s21
#endif  // VIEWER_STRATEGYRECORDER_H
