#include "Scene.h"
#include <QKeyEvent>
#include <QPainter>

Scene::Scene(QObject* parent)
    : QGraphicsScene(parent) {
    tank = new Tank();
    addItem(tank);
    tank->setPos(400, 300); // Устанавливаем танк в центр сцены
}

void Scene::keyPressEvent(QKeyEvent* event) {
    if (tank) {
        tank->keyPressEvent(event);
    }
}

void Scene::drawBackground(QPainter* painter, const QRectF& rect) {
    Q_UNUSED(rect);
    painter->fillRect(sceneRect(), QColor(164, 191, 51)); // Устанавливаем цвет фона
}
