#include "style_panel.h"

#include "QRadioButton"
#include "iostream"
#include "ui_style_panel.h"
StylePanel::StylePanel(Mediator *mediator,
                       s21::StyleHandlerController *style_controller_,
                       QWidget *parent)
    : mediator_(mediator),
      style_controller_(style_controller_),
      QWidget(parent),
      ui(new Ui::StylePanel) {
  ui->setupUi(this);
  ConnectSpinBoxes();
  ConnectRadioButtons();
}

StylePanel::~StylePanel() { delete ui; }

void StylePanel::SetEnabledModifiers(bool status) {
  ui->spinBox_point_size->setEnabled(status);
  ui->spinBox_line_width->setEnabled(status);
  ui->line_type_dotted->setEnabled(status);
  ui->line_type_solid->setEnabled(status);
  ui->display_method_none->setEnabled(status);
  ui->display_method_circle->setEnabled(status);
  ui->display_method_square->setEnabled(status);
  ui->projection_f->setEnabled(status);
  ui->projection_p->setEnabled(status);
  ui->color_line_r->setEnabled(status);
  ui->color_line_g->setEnabled(status);
  ui->color_line_b->setEnabled(status);
  ui->color_point_r->setEnabled(status);
  ui->color_point_g->setEnabled(status);
  ui->color_point_b->setEnabled(status);
  ui->color_back_r->setEnabled(status);
  ui->color_back_g->setEnabled(status);
  ui->color_back_b->setEnabled(status);
}

void StylePanel::SetInitSettings(std::map<std::string, int> drawing_styles,
                                 std::map<std::string, int> colors,
                                 std::map<std::string, double> sizes) {
  ui->spinBox_point_size->setValue(sizes["point_size"]);
  ui->spinBox_line_width->setValue(sizes["line_width"]);
  if (drawing_styles["dotted_line"]) {
    ui->line_type_dotted->setChecked(true);
  } else {
    ui->line_type_solid->setChecked(true);
  }
  if (drawing_styles["projection"]) {
    ui->projection_f->setChecked(true);
  } else {
    ui->projection_p->setChecked(true);
  }
  if (drawing_styles["point_type"] == 1) {
    ui->display_method_square->setChecked(true);
  } else if (drawing_styles["point_type"] == 2) {
    ui->display_method_circle->setChecked(true);
  } else {
    ui->display_method_none->setChecked(true);
  }
  ui->color_line_r->setValue(colors["color_line_r"]);
  ui->color_line_g->setValue(colors["color_line_g"]);
  ui->color_line_b->setValue(colors["color_line_b"]);
  ui->color_point_r->setValue(colors["color_point_r"]);
  ui->color_point_g->setValue(colors["color_point_g"]);
  ui->color_point_b->setValue(colors["color_point_b"]);
  ui->color_back_r->setValue(colors["color_back_r"]);
  ui->color_back_g->setValue(colors["color_back_g"]);
  ui->color_back_b->setValue(colors["color_back_b"]);
}

void StylePanel::ConnectRadioButtons() {
  for (auto &button : ui->PointGroup->buttons()) {
    connect(button, &QRadioButton::clicked, this,
            &StylePanel::PointTypeChanged);
  }
  for (auto &button : ui->LineGroup->buttons()) {
    connect(button, &QRadioButton::clicked, this, &StylePanel::LineTypeChanged);
  }
  for (auto &button : ui->ProjectionGroup->buttons()) {
    connect(button, &QRadioButton::clicked, this,
            &StylePanel::ProjectionTypeChanged);
  }
}

void StylePanel::ConnectSpinBoxes() {
  connect(ui->color_back_r, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_back_g, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_back_b, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_line_r, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_line_g, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_line_b, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_point_r, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_point_g, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->color_point_b, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &StylePanel::ColorValueChanged);
  connect(ui->spinBox_line_width,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &StylePanel::LineWidthValueChanged);
  connect(ui->spinBox_point_size,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &StylePanel::PointSizeValueChangedB);
}

void StylePanel::PointTypeChanged(bool checked) {
  auto button_ptr = static_cast<QRadioButton *>(sender());
  auto button_name = button_ptr->objectName();
  int value;
  if (button_name == "display_method_none") {
    value = 0;
  } else if (button_name == "display_method_square") {
    value = 1;
  } else {
    value = 2;
  }
  mediator_->RadioButtonChanged("point_type",
                                style_controller_->GetDrawingStyles(), value);
}

void StylePanel::LineTypeChanged(bool checked) {
  auto button_ptr = static_cast<QRadioButton *>(sender());
  auto button_name = button_ptr->objectName();
  int value = 0;
  if (button_name == "line_type_dotted") {
    value = 1;
  }
  mediator_->RadioButtonChanged("dotted_line",
                                style_controller_->GetDrawingStyles(), value);
}

void StylePanel::ProjectionTypeChanged(bool checked) {
  auto button_ptr = static_cast<QRadioButton *>(sender());
  auto button_name = button_ptr->objectName();
  int value = 0;
  if (button_name == "projection_f") {
    value = 1;
  }
  mediator_->RadioButtonChanged("projection",
                                style_controller_->GetDrawingStyles(), value);
}

void StylePanel::ColorValueChanged(int value) {
  auto spinbox_ptr = static_cast<QSpinBox *>(sender());
  mediator_->ColorValueChanged(spinbox_ptr->objectName(),
                               style_controller_->GetColors(), value);
}

void StylePanel::LineWidthValueChanged(double value) {
  mediator_->SizeStyleValueChanged("line_width", style_controller_->GetSizes(),
                                   value);
}

void StylePanel::PointSizeValueChangedB(double value) {
  mediator_->SizeStyleValueChanged("point_size", style_controller_->GetSizes(),
                                   value);
}
