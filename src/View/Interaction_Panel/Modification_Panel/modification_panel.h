#ifndef MODIFICATION_PANEL_H
#define MODIFICATION_PANEL_H

#include <QWidget>

#include "../../../Controller/Object_Controller/object_controller.h"
#include "../../Panel_Mediator/mediator.h"

namespace Ui {
class ModificationPanel;
}

class ModificationPanel : public QWidget {
  Q_OBJECT

 public:
  explicit ModificationPanel(Mediator *mediator,
                             s21::ObjectHandlerController *object_controller,
                             QWidget *parent = nullptr);
  ~ModificationPanel();

  void SetEnabledModifiers(bool status);

 private:
  Ui::ModificationPanel *ui;
  Mediator *mediator_;
  s21::ObjectHandlerController *object_controller_;
 private slots:
  void ConnectSpinBoxes();

  void CoordinateXValueChanged(int value);
  void CoordinateYValueChanged(int value);
  void CoordinateZValueChanged(int value);

  void AngleXValueChanged(double value);
  void AngleYValueChanged(double value);
  void AngleZValueChanged(double value);

  void ScaleValueChanged(double value);
};

#endif  // STYLE_PANEL_H
