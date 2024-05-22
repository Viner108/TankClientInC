#include "Tank.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QtMath>

Tank::Tank(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), rotationAngle(0) {
    setPixmap(QPixmap(":/image/tankActive1.png").scaled(50, 50)); // Масштабируем изображение танка
    setTransformOriginPoint(boundingRect().center()); // Устанавливаем центр поворота танка

    turret = new Turret();
    turret->setParentItem(this); // Устанавливаем родительский элемент для башни
    turret->setPos(boundingRect().center() - QPointF(turret->boundingRect().width() / 2, turret->boundingRect().height() / 2)); // Центрируем башню относительно танка
    turret->setTransformOriginPoint(turret->boundingRect().center());
}

void Tank::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        rotationAngle -= 15;
        if (rotationAngle < 0) rotationAngle += 360;
        setRotation(rotationAngle);
        break;
    case Qt::Key_Right:
        rotationAngle += 15;
        if (rotationAngle >= 360) rotationAngle -= 360;
        setRotation(rotationAngle);
        break;
    case Qt::Key_Up: {
        // Перемещение вперед
        double radians = qDegreesToRadians(static_cast<double>(rotationAngle));
        double dx = 10 * qCos(radians);
        double dy = 10 * qSin(radians);
        setPos(x() + dx, y() + dy);
        break;
    }
    case Qt::Key_Down: {
        // Перемещение назад
        double radians = qDegreesToRadians(static_cast<double>(rotationAngle));
        double dx = -10 * qCos(radians);
        double dy = -10 * qSin(radians);
        setPos(x() + dx, y() + dy);
        break;
    }
    case Qt::Key_Q:
        turret->rotate(-15);
        break;
    case Qt::Key_E:
        turret->rotate(15);
        break;
    case Qt::Key_Space:
        shoot();
        break;
    }
}

void Tank::shoot() {
    double radians = qDegreesToRadians(static_cast<double>(turret->rotation() + rotation()));
    QPointF turretCenter = mapToScene(turret->boundingRect().center());
    double bulletX = turretCenter.x() + 25 * qCos(radians);
    double bulletY = turretCenter.y() + 25 * qSin(radians);
    Bullet* bullet = new Bullet(bulletX, bulletY, turret->rotation() + rotation());
    scene()->addItem(bullet);
    bullet->setPos(bulletX, bulletY);
}
