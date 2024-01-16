#include "mediator.h"

#include "iostream"

Mediator::Mediator(s21::StyleHandlerController *style_controller,
                   s21::ObjectHandlerController *object_controller,
                   QObject *parent)
    : object_controller_(object_controller),
      style_controller_(style_controller),
      QObject{parent} {}

void Mediator::ColorValueChanged(const QString &spin_box_name,
                                 std::map<std::string, int> colors, int value) {
  colors[spin_box_name.toStdString()] = value;
  style_controller_->SetColors(colors);
  emit ColorDataChanged(colors);
}

void Mediator::SizeStyleValueChanged(const QString &spin_box_name,
                                     std::map<std::string, double> sizes,
                                     int value) {
  sizes[spin_box_name.toStdString()] = value;
  style_controller_->SetSizes(sizes);
  emit SizeStyleChanged(sizes);
}

void Mediator::RadioButtonChanged(const QString &radio_button_name,
                                  std::map<std::string, int> drawing_styles,
                                  int value) {
  drawing_styles[radio_button_name.toStdString()] = value;
  style_controller_->SetDrawingStyles(drawing_styles);
  emit DrawingStyleChanged(drawing_styles);
}

void Mediator::CoordinateValueChanged(const QString &spin_box_name,
                                      std::vector<s21::Coordinates> coordinates,
                                      int value) {
  if (spin_box_name == "coordinate_x") {
    coordinates[0].x = (int)value;
  } else if (spin_box_name == "coordinate_y") {
    coordinates[0].y = (int)value;
  } else {
    coordinates[0].z = (int)value;
  }
  object_controller_->SetCoordinates(coordinates);
  emit CoordinatesDataChanged(coordinates);
}

void Mediator::AngleValueChanged(const QString &spin_box_name,
                                 std::vector<s21::Coordinates> angles,
                                 int value) {
  if (spin_box_name == "angle_x") {
    angles[0].x = (int)value;
  } else if (spin_box_name == "angle_y") {
    angles[0].y = (int)value;
  } else {
    angles[0].z = (int)value;
  }
  object_controller_->SetAngles(angles);
  emit AnglesDataChanged(angles);
}

void Mediator::ScaleValueChanged(const QString &spin_box_name, double scale,
                                 double value) {
  scale = value;
  object_controller_->SetScale(scale);
  emit ScaleDataChanged(scale);
}
