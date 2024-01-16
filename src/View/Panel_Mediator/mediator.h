#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <vector>

#include "../../Controller/Object_Controller/object_controller.h"
#include "../../Controller/Style_Controller/style_controlloer.h"
#include "../../Model/Object_Handler/common.h"

class Mediator : public QObject {
  Q_OBJECT
 public:
  Mediator(s21::StyleHandlerController *style_controller,
           s21::ObjectHandlerController *object_controller,
           QObject *parent = nullptr);

 public slots:
  void ColorValueChanged(const QString &spin_box_name,
                         std::map<std::string, int> colors, int value);

  void SizeStyleValueChanged(const QString &spin_box_name,
                             std::map<std::string, double> colors, int value);

  void RadioButtonChanged(const QString &radio_button_name,
                          std::map<std::string, int> drawing_styles, int value);

  void ScaleValueChanged(const QString &spin_box_name, double scale,
                         double value);

  void AngleValueChanged(const QString &spin_box_name,
                         std::vector<s21::Coordinates> angles, int value);

  void CoordinateValueChanged(const QString &spin_box_name,
                              std::vector<s21::Coordinates> coordinates,
                              int value);
 signals:
  void ColorDataChanged(const std::map<std::string, int> colors);
  void DrawingStyleChanged(const std::map<std::string, int> drawing_styles);
  void SizeStyleChanged(const std::map<std::string, double> drawing_styles);

  void ScaleDataChanged(const double Scale);
  void AnglesDataChanged(const std::vector<s21::Coordinates> Angles);
  void CoordinatesDataChanged(const std::vector<s21::Coordinates> coordinates);

  //  void StyleDataChanged(std::map<std::string, int> type_of_points);
 private:
  s21::StyleHandlerController *style_controller_;
  s21::ObjectHandlerController *object_controller_;
};

#endif  // MEDIATOR_H
