#include "object_observer.h"

void ObjectObserver::ConnectUpdaters(Mediator *mediator) {
  connect(mediator, &Mediator::ColorDataChanged, this,
          &ObjectObserver::UpdateColors);
  connect(mediator, &Mediator::DrawingStyleChanged, this,
          &ObjectObserver::UpdateDrawingStyles);
  connect(mediator, &Mediator::DrawingStyleChanged, this,
          &ObjectObserver::UpdateDrawingStyles);
  connect(mediator, &Mediator::SizeStyleChanged, this,
          &ObjectObserver::UpdateSizeStyle);
  connect(mediator, &Mediator::CoordinatesDataChanged, this,
          &ObjectObserver::UpdateCoordinates);
  connect(mediator, &Mediator::AnglesDataChanged, this,
          &ObjectObserver::UpdateAngles);
  connect(mediator, &Mediator::ScaleDataChanged, this,
          &ObjectObserver::UpdateScale);
}

void ObjectObserver::UpdateColors(std::map<std::string, int> colors) {
  colors_ = colors;
  update();
}

void ObjectObserver::UpdateDrawingStyles(
    std::map<std::string, int> drawing_styles) {
  drawing_styles_ = drawing_styles;
  update();
}

void ObjectObserver::UpdateSizeStyle(
    std::map<std::string, double> size_styles) {
  size_styles_ = size_styles;
  update();
}

void ObjectObserver::UpdateCoordinates(
    std::vector<s21::Coordinates> coordinates) {
  coordinates_ = coordinates;
  update();
}

void ObjectObserver::UpdateAngles(std::vector<s21::Coordinates> angles) {
  angles_ = angles;
  update();
}

void ObjectObserver::UpdateScale(double scale) {
  scale_ = scale;
  update();
}