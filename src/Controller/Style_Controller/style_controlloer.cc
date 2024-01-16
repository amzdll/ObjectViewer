#include "style_controlloer.h"

namespace s21 {
StyleHandlerController::StyleHandlerController(s21::StyleHandler *style_model)
    : style_model_(style_model){};

std::map<std::string, int> StyleHandlerController::GetColors() {
  return style_model_->GetColors();
}

void StyleHandlerController::SetColors(std::map<std::string, int> colors) {
  style_model_->SetColors(colors);
}

std::map<std::string, double> StyleHandlerController::GetSizes() {
  return style_model_->GetSizes();
}

void StyleHandlerController::SetSizes(std::map<std::string, double> sizes) {
  style_model_->SetSizes(sizes);
}

std::map<std::string, int> StyleHandlerController::GetDrawingStyles() {
  return style_model_->GetDrawingStyles();
}

void StyleHandlerController::SetDrawingStyles(
    std::map<std::string, int> drawing_styles) {
  style_model_->SetDrawingStyles(drawing_styles);
}

}  // namespace s21