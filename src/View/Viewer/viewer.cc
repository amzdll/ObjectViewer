#include "viewer.h"

#include <QMovie>

#include "ui_viewer.h"

Viewer::Viewer(s21::ObjectHandlerController* object_controller,
               s21::StyleHandlerController* style_controller, QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::Viewer),
      object_controller_(object_controller),
      style_controller_(style_controller) {
  ui->setupUi(this);

  mediator_ = new Mediator(style_controller_, object_controller_);
  object_observer_ = new ObjectObserver(mediator_);
  modification_panel_ = new ModificationPanel(mediator_, object_controller_);
  style_panel_ = new StylePanel(mediator_, style_controller_);

  style_panel_->SetInitSettings(style_controller_->GetDrawingStyles(),
                                style_controller_->GetColors(),
                                style_controller_->GetSizes());

  ui->object_observer_window->addWidget(object_observer_);
  ui->modification_panel->addWidget(modification_panel_);
  ui->style_panel->addWidget(style_panel_);

  connect(ui->button_open_file, SIGNAL(clicked()), this, SLOT(OpenFile()));
  connect(ui->button_create_img, SIGNAL(clicked()), this, SLOT(MakeScreen()));
}

Viewer::~Viewer() {
  delete ui;
  delete mediator_;
  delete object_observer_;
  delete modification_panel_;
  delete style_panel_;
}

void Viewer::OpenFile() {
  QString file_path = (QFileDialog::getOpenFileName(
      this, "Open a file", "./obj_templates/", "(*.obj)"));
  if (object_controller_->RecordDataFromFile(file_path.toStdString())) {
    ui->input_filename->setText("  " + file_path);
    ui->info_of_object->setText(
        "vertexes: " +
        QString::number(object_controller_->GetData().vertices.size()) + "\t" +
        "facets: " +
        QString::number(object_controller_->GetData().facets.size() / 6));
    object_observer_->SetInitialStyleSettings(
        style_controller_->GetSizes(), style_controller_->GetDrawingStyles(),
        style_controller_->GetColors());
    object_observer_->SetObjectData(object_controller_->GetData());
    object_observer_->SetSceneParameters(
        object_controller_->GetSceneParameters());

    style_panel_->SetEnabledModifiers(true);
    modification_panel_->SetEnabledModifiers(true);

    ui->button_create_img->setEnabled(true);
  }
}

void Viewer::MakeScreen() {
  QLayoutItem* layoutItem = ui->object_observer_window->itemAt(0);
  if (layoutItem) {
    QWidget* widget = layoutItem->widget();
    if (widget && widget->inherits("QOpenGLWidget")) {
      QOpenGLWidget* glWidget = qobject_cast<QOpenGLWidget*>(widget);
      if (glWidget) {
        QImage screenshot = glWidget->grabFramebuffer();
        QString filename =
            QFileDialog::getSaveFileName(nullptr, "Сохранить скриншот", "",
                                         "BMP(*.bmp);; JPEG(*.jpg *.jpeg)");
        if (!filename.isEmpty()) {
          screenshot.save(filename);
        }
      }
    }
  }
}
