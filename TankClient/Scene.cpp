#include "Scene.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QPainter>
#include <QDataStream>
#include <QDebug>

Scene::Scene(QObject* parent)
    : QGraphicsScene(parent), socket(nullptr) {
    tank = new Tank();
    addItem(tank);
    tank->setPos(400, 300); // Устанавливаем танк в центр сцены
}

void Scene::setSocket(QTcpSocket* socket) {
    this->socket = socket;
}

void Scene::keyPressEvent(QKeyEvent* event) {
    if (socket) {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << event->key();
        socket->write(data);
        qDebug() << "Sent key event to server:" << event->key();
    }
}

void Scene::updateTankPosition(const QPointF& position, int angle, int turretAngle) {
    qDebug() << "Updating tank position to:" << position << "rotation angle:" << angle << "turret angle:" << turretAngle;
    tank->setPos(position);
    tank->setRotation(angle);
    tank->updateTurretRotation(turretAngle);
}

void Scene::clearBullets() {
    QList<QGraphicsItem*> items = this->items();
    for (QGraphicsItem* item : items) {
        Bullet* bullet = dynamic_cast<Bullet*>(item);
        if (bullet) {
            qDebug() << "Deleting bullet at position:" << bullet->pos();
            this->removeItem(bullet);
            delete bullet;
        }
    }
}
