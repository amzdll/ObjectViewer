#include "style_handler.h"

namespace s21 {

StyleHandler::StyleHandler() { ImportSetting(); }

void StyleHandler::ExportSettings() {
  QString file_path =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
      "/.3D_viewer";
  QDir().mkpath(file_path);
  QSettings settings(file_path + "/settings.ini", QSettings::IniFormat);

  for (const auto& item : sizes_) {
    settings.setValue(QString::fromStdString(item.first),
                      QVariant(item.second));
  }

  for (const auto& item : drawing_styles_) {
    settings.setValue(QString::fromStdString(item.first),
                      QVariant(item.second));
  }

  for (const auto& item : colors_) {
    settings.setValue(QString::fromStdString(item.first),
                      QVariant(item.second));
  }
}

void StyleHandler::ImportSetting() {
  QString file_path =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
      "/.3D_viewer";
  QSettings settings(file_path + "/settings.ini", QSettings::IniFormat);

  for (const auto& item : sizes_) {
    sizes_[item.first] =
        settings.value(QString::fromStdString(item.first), 0).toFloat();
  }

  for (const auto& item : drawing_styles_) {
    drawing_styles_[item.first] =
        settings.value(QString::fromStdString(item.first), 0).toInt();
  }

  for (const auto& item : colors_) {
    colors_[item.first] =
        settings.value(QString::fromStdString(item.first), 0).toInt();
  }
}

std::map<std::string, int> StyleHandler::GetColors() { return colors_; }

std::map<std::string, double> StyleHandler::GetSizes() { return sizes_; }

std::map<std::string, int> StyleHandler::GetDrawingStyles() {
  return drawing_styles_;
}

void StyleHandler::SetColors(std::map<std::string, int> colors) {
  colors_ = colors;
  ExportSettings();
}

void StyleHandler::SetSizes(std::map<std::string, double> sizes) {
  sizes_ = sizes;
  ExportSettings();
}

void StyleHandler::SetDrawingStyles(std::map<std::string, int> drawing_styles) {
  drawing_styles_ = drawing_styles;
  ExportSettings();
}

}  // namespace s21
