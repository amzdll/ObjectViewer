#ifndef CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_
#define CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_

#include "../../Model/Style_Handler/style_handler.h"

namespace s21 {
class StyleHandlerController {
 public:
  StyleHandlerController(s21::StyleHandler *style_model);

  std::map<std::string, int> GetColors();
  std::map<std::string, double> GetSizes();
  std::map<std::string, int> GetDrawingStyles();

  void SetColors(std::map<std::string, int> colors);
  void SetSizes(std::map<std::string, double> sizes);
  void SetDrawingStyles(std::map<std::string, int> drawing_styles);

 private:
  s21::StyleHandler *style_model_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_
