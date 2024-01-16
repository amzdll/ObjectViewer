#ifndef STYLE_PANEL_H
#define STYLE_PANEL_H

#include <QWidget>
#include <QtWidgets/QSpinBox>
#include <map>

#include "../../../Controller/Style_Controller/style_controlloer.h"
#include "../../Panel_Mediator/mediator.h"

namespace Ui {
class StylePanel;
}

class StylePanel : public QWidget {
  Q_OBJECT

 public:
  ~StylePanel();

  explicit StylePanel(Mediator *mediator,
                      s21::StyleHandlerController *style_controller_,
                      QWidget *parent = nullptr);

  void SetEnabledModifiers(bool status);
  void SetInitSettings(std::map<std::string, int> drawing_styles,
                       std::map<std::string, int> colors,
                       std::map<std::string, double> sizes);

 private:
  Ui::StylePanel *ui;
  Mediator *mediator_;
  s21::StyleHandlerController *style_controller_;

 private slots:
  void ConnectRadioButtons();
  void ConnectSpinBoxes();

  void PointTypeChanged(bool checked);
  void LineTypeChanged(bool checked);
  void ProjectionTypeChanged(bool checked);

  void ColorValueChanged(int value);

  void LineWidthValueChanged(double value);
  void PointSizeValueChangedB(double value);
};

#endif  // STYLE_PANEL_H
