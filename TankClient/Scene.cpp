#include "Scene.h"
#include <QPainter>
#include <QKeyEvent>

Scene::Scene(QWidget* parent)
    : QWidget(parent), tank(nullptr) {
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus); // Даем фокус для получения событий клавиатуры
}

void Scene::setTank(Tank* tank) {
    this->tank = tank;
}

void Scene::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(rect(), QColor(164, 191, 51)); // Задаем цвет фона сцены
}

void Scene::keyPressEvent(QKeyEvent* event) {
    if (tank) {
        switch (event->key()) {
        case Qt::Key_Left:
            tank->rotateTank(-15); // Поворот против часовой стрелки
            break;
        case Qt::Key_Right:
            tank->rotateTank(15); // Поворот по часовой стрелке
            break;
        case Qt::Key_Up:
            tank->moveTank(10, 0); // Перемещение вверх
            break;
        case Qt::Key_Down:
            tank->moveTank(-10, 0); // Перемещение вниз
            break;
        case Qt::Key_Q:
            tank->rotateTurret(-15); // Поворот башни против часовой стрелки
            break;
        case Qt::Key_E:
            tank->rotateTurret(15); // Поворот башни по часовой стрелке
            break;
        }

    }
}
