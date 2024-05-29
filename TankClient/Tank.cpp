#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QtMath>
#include <QDebug>

Tank::Tank(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), rotationAngle(0) {
    setPixmap(QPixmap(":/image/tankActive1.png").scaled(50, 50)); // Масштабируем изображение танка
    setTransformOriginPoint(boundingRect().center()); // Устанавливаем центр поворота танка

    turret = new Turret();
    turret->setParentItem(this); // Устанавливаем родительский элемент для башни
    turret->setPos(boundingRect().center() - QPointF(turret->boundingRect().width() / 2, turret->boundingRect().height() / 2)); // Центрируем башню относительно танка
    turret->setTransformOriginPoint(turret->boundingRect().center());
}

void Tank::updateTurretRotation(int angle) {
    qDebug() << "Updating turret rotation to:" << angle;
    turret->setRotation(angle);
}
