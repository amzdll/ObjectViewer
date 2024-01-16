#ifndef CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_
#define CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_

#include <QDir>
#include <QSettings>
#include <QStandardPaths>
#include <iostream>
#include <map>
#include <string>

namespace s21 {
class StyleHandler {
 public:
  StyleHandler();
  //  StyleHandler() { ImportSetting(); }

  void ImportSetting();
  void ExportSettings();

  std::map<std::string, int> GetColors();
  std::map<std::string, double> GetSizes();
  void SetDrawingStyles(std::map<std::string, int> drawing_styles);

  void SetColors(std::map<std::string, int> colors);
  void SetSizes(std::map<std::string, double> sizes);
  std::map<std::string, int> GetDrawingStyles();

 private:
  std::map<std::string, double> sizes_{
      std::pair<std::string, double>("line_width", 0),
      std::pair<std::string, double>("point_size", 0)};

  std::map<std::string, int> drawing_styles_{
      std::pair<std::string, int>("point_type", 0),
      std::pair<std::string, int>("projection", 0),
      std::pair<std::string, int>("dotted_line", 0)};

  std::map<std::string, int> colors_{
      std::pair<std::string, int>("color_line_r", 0),
      std::pair<std::string, int>("color_line_g", 0),
      std::pair<std::string, int>("color_line_b", 0),
      std::pair<std::string, int>("color_back_r", 0),
      std::pair<std::string, int>("color_back_g", 0),
      std::pair<std::string, int>("color_back_b", 0),
      std::pair<std::string, int>("color_point_r", 0),
      std::pair<std::string, int>("color_point_g", 0),
      std::pair<std::string, int>("color_point_b", 0)};
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_
