#include "Model/Object_Handler/object_facade.h"
#include "Model/Style_Handler/style_handler.h"

#include "Controller/Object_Controller/object_controller.h"
#include "Controller/Style_Controller/style_controlloer.h"

#include "View/Viewer/viewer.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  s21::ObjectFacade object_model;
  s21::StyleHandler style_model;

  s21::ObjectHandlerController object_controller(&object_model);
  s21::StyleHandlerController style_controller(&style_model);

  QApplication application(argc, argv);
  Viewer window(&object_controller, &style_controller);

  window.show();
  return application.exec();
}
