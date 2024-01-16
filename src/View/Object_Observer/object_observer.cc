#include "object_observer.h"

#include "ui_object_observer.h"

ObjectObserver::ObjectObserver(Mediator *mediator, QWidget *parent)
    : QOpenGLWidget(parent) {
  setGeometry(0, 0, 700, 700);

  ConnectUpdaters(mediator);
}

void ObjectObserver::mousePressEvent(QMouseEvent *mo) { m_pos_ = mo->pos(); }

void ObjectObserver::mouseMoveEvent(QMouseEvent *mo) {
  int dx = mo->pos().x() - m_pos_.x();
  int dy = mo->pos().y() - m_pos_.y();
  x_rot_m_ += 1.0 / M_PI * dy;
  y_rot_m_ += 1.0 / M_PI * dx;
  m_pos_ = mo->pos();
  update();
}

void ObjectObserver::SetInitialStyleSettings(
    std::map<std::string, double> size_styles,
    std::map<std::string, int> drawing_styles,
    std::map<std::string, int> colors) {
  colors_ = colors;
  drawing_styles_ = drawing_styles;
  size_styles_ = size_styles;
}

void ObjectObserver::SetSceneParameters(
    std::map<std::string, float> scene_parameters) {
  scene_parameters_ = scene_parameters;
}

void ObjectObserver::SetObjectData(s21::ObjectData object_data) {
  FillBuffers(object_data);
  update();
}

void ObjectObserver::FillBuffers(s21::ObjectData object_data) {
  facets_size_ = object_data.facets.size();

  glGenBuffers(1, &facets_buffer_);
  glGenBuffers(1, &vertices_buffer_);

  glBindBuffer(GL_ARRAY_BUFFER, vertices_buffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facets_buffer_);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               object_data.facets.size() * sizeof(unsigned int),
               object_data.facets.data(), GL_STATIC_DRAW);
  glBufferData(GL_ARRAY_BUFFER,
               object_data.vertices.size() * sizeof(s21::Coordinates),
               object_data.vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ObjectObserver::initializeGL() { glEnable(GL_DEPTH_TEST); }

void ObjectObserver::resizeGL(int w, int h) {}

void ObjectObserver::paintGL() {
  glClearColor((double)colors_["color_back_r"] / 255.0,
               (double)colors_["color_back_g"] / 255.0,
               (double)colors_["color_back_b"] / 255.0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  SetProjection();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(angles_[0].x + (int)x_rot_m_ % 360, 1, 0, 0);
  glRotatef(angles_[0].y + (int)y_rot_m_ % 360, 0, 1, 0);
  glRotatef(angles_[0].z, 0, 0, 1);
  glTranslatef(coordinates_[0].x, coordinates_[0].y, coordinates_[0].z);
  glScalef(scale_, scale_, scale_);

  DrawModel();
}

void ObjectObserver::SetProjection() {
  if (drawing_styles_["projection"]) {
    float left =
        scene_parameters_["center_x"] - scene_parameters_["scene_size"];
    float right =
        scene_parameters_["center_x"] + scene_parameters_["scene_size"];
    float bottom =
        scene_parameters_["center_y"] - scene_parameters_["scene_size"];
    float top = scene_parameters_["center_y"] + scene_parameters_["scene_size"];
    float near =
        scene_parameters_["center_z"] - scene_parameters_["scene_size"];
    float far = scene_parameters_["center_z"] + scene_parameters_["scene_size"];

    glOrtho(left, right, bottom, top, near, far);
  } else {
    float top = tan(60.0 * M_PI / 180 / 2);
    float bottom = -top;
    float right = top;
    float left = -right;

    glFrustum(left, right, bottom, top, 1, 1000000);
    glTranslatef(-scene_parameters_["center_x"], -scene_parameters_["center_y"],
                 -(scene_parameters_["scene_size"] + 1));
  }
}

void ObjectObserver::DrawModel() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST | GL_LINE_STIPPLE);

  if (drawing_styles_["dotted_line"]) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x1010);
  }

  glLineWidth(size_styles_["line_width"]);
  glColor3d((double)colors_["color_line_r"] / 255,
            (double)colors_["color_line_g"] / 255,
            (double)colors_["color_line_b"] / 255);
  glEnableClientState(GL_VERTEX_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, vertices_buffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facets_buffer_);

  glVertexPointer(3, GL_FLOAT, 0, nullptr);

  glDrawElements(GL_LINES, facets_size_, GL_UNSIGNED_INT, nullptr);

  DrawPoints();
  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glDisable(GL_DEPTH_BUFFER_BIT | GL_LINE_STIPPLE);
}

void ObjectObserver::DrawPoints() {
  if (drawing_styles_["point_type"]) {
    if (drawing_styles_["point_type"] == 1) {
      glDisable(GL_POINT_SMOOTH);
    } else if (drawing_styles_["point_type"] == 2) {
      glEnable(GL_POINT_SMOOTH);
    }
    glPointSize(size_styles_["point_size"]);
    glColor3f((double)colors_["color_point_r"] / 255,
              (double)colors_["color_point_g"] / 255,
              (double)colors_["color_point_b"] / 255);
    glDrawElements(GL_POINTS, facets_size_, GL_UNSIGNED_INT, nullptr);
  }
}
