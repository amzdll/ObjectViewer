#include "modification_panel.h"

#include "ui_modification_panel.h"

ModificationPanel::ModificationPanel(
    Mediator *mediator, s21::ObjectHandlerController *object_controller,
    QWidget *parent)
    : mediator_(mediator),
      object_controller_(object_controller),
      QWidget(parent),
      ui(new Ui::ModificationPanel) {
  ui->setupUi(this);
  ConnectSpinBoxes();
}

ModificationPanel::~ModificationPanel() { delete ui; }

void ModificationPanel::SetEnabledModifiers(bool status) {
  ui->spinBox_scale->setEnabled(status);

  ui->spinBox_x_angle->setEnabled(status);
  ui->spinBox_y_angle->setEnabled(status);
  ui->spinBox_z_angle->setEnabled(status);

  ui->spinBox_x->setEnabled(status);
  ui->spinBox_y->setEnabled(status);
  ui->spinBox_z->setEnabled(status);
}

void ModificationPanel::ConnectSpinBoxes() {
  connect(ui->spinBox_x, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &ModificationPanel::CoordinateXValueChanged);
  connect(ui->spinBox_y, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &ModificationPanel::CoordinateYValueChanged);
  connect(ui->spinBox_z, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &ModificationPanel::CoordinateZValueChanged);

  connect(ui->spinBox_x_angle,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ModificationPanel::AngleXValueChanged);
  connect(ui->spinBox_y_angle,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ModificationPanel::AngleYValueChanged);
  connect(ui->spinBox_z_angle,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ModificationPanel::AngleZValueChanged);

  connect(ui->spinBox_scale,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ModificationPanel::ScaleValueChanged);
}

void ModificationPanel::CoordinateXValueChanged(int value) {
  mediator_->CoordinateValueChanged(
      "coordinate_x", object_controller_->GetCoordinates(), value);
}

void ModificationPanel::CoordinateYValueChanged(int value) {
  mediator_->CoordinateValueChanged(
      "coordinate_y", object_controller_->GetCoordinates(), value);
}

void ModificationPanel::CoordinateZValueChanged(int value) {
  mediator_->CoordinateValueChanged(
      "coordinate_z", object_controller_->GetCoordinates(), value);
}

void ModificationPanel::AngleXValueChanged(double value) {
  mediator_->AngleValueChanged("angle_x", object_controller_->GetAngles(),
                               value);
}

void ModificationPanel::AngleYValueChanged(double value) {
  mediator_->AngleValueChanged("angle_y", object_controller_->GetAngles(),
                               value);
}

void ModificationPanel::AngleZValueChanged(double value) {
  mediator_->AngleValueChanged("angle_z", object_controller_->GetAngles(),
                               value);
}

void ModificationPanel::ScaleValueChanged(double value) {
  mediator_->ScaleValueChanged("scale", object_controller_->GetScale(), value);
}
