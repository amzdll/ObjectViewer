#ifndef OBJECT_OBSERVER_H
#define OBJECT_OBSERVER_H

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QMouseEvent>
#include <QWidget>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "../../Controller/Object_Controller/object_controller.h"
#include "../Panel_Mediator/mediator.h"

namespace Ui {
class ObjectObserver;
}

class ObjectObserver : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit ObjectObserver(Mediator *mediator, QWidget *parent = nullptr);
  ~ObjectObserver() = default;

  void SetObjectData(s21::ObjectData object_data);
  void SetInitialStyleSettings(std::map<std::string, double> size_styles,
                               std::map<std::string, int> drawing_styles,
                               std::map<std::string, int> colors);
  void SetSceneParameters(std::map<std::string, float> scene_parameters);

 private:
  double scale_ = 1;
  GLuint vertices_buffer_;
  GLuint facets_buffer_;
  size_t facets_size_;
  std::map<std::string, double> sizes_;
  std::map<std::string, int> colors_;
  std::map<std::string, int> drawing_styles_;
  std::map<std::string, double> size_styles_;
  std::map<std::string, float> scene_parameters_;
  std::vector<s21::Coordinates> coordinates_{{0, 0, 0}};
  std::vector<s21::Coordinates> angles_{{0, 0, 0}};
  Ui::ObjectObserver *ui{};
  float x_rot_m_{}, y_rot_m_{};
  QPoint m_pos_;

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void mousePressEvent(QMouseEvent *mo);
  void mouseMoveEvent(QMouseEvent *mo);

  void FillBuffers(s21::ObjectData object_data);
  void UpdateColors(std::map<std::string, int> colors);
  void UpdateDrawingStyles(std::map<std::string, int> drawing_styles);
  void UpdateSizeStyle(std::map<std::string, double> size_styles);
  void UpdateCoordinates(std::vector<s21::Coordinates> coordinates);
  void UpdateAngles(std::vector<s21::Coordinates> angles);
  void UpdateScale(double scale);
  void DrawModel();
  void DrawPoints();
  void SetProjection();
  void ConnectUpdaters(Mediator *mediator);
};

#endif  // OBJECT_OBSERVER_H
