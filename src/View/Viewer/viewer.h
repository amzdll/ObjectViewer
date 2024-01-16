#ifndef VIEWER_H
#define VIEWER_H

#define GL_SILENCE_DEPRECATION

#include <QFileDialog>
#include <QMainWindow>
#include <QString>

#include "../../Controller/Object_Controller/object_controller.h"
#include "../../Controller/Style_Controller/style_controlloer.h"
#include "../Interaction_Panel/Modification_Panel/modification_panel.h"
#include "../Interaction_Panel/Style_Panel/style_panel.h"
#include "../Object_Observer/object_observer.h"
#include "../Panel_Mediator/mediator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(s21::ObjectHandlerController *object_controller,
         s21::StyleHandlerController *style_controller,
         QWidget *parent = nullptr);

  ~Viewer();

 private:
  Ui::Viewer *ui;

  Mediator *mediator_;

  ObjectObserver *object_observer_;
  StylePanel *style_panel_;
  ModificationPanel *modification_panel_;

  s21::ObjectHandlerController *object_controller_;
  s21::StyleHandlerController *style_controller_;

 private slots:
  void OpenFile();
  void MakeScreen();
};

#endif  // VIEWER_H
