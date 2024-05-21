#include "Scene.h"
#include <QPainter>

Scene::Scene(QWidget* parent)
    : QWidget(parent) {
    setFixedSize(800, 600);
}

void Scene::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::green); // Задаем цвет фона сцены
}
