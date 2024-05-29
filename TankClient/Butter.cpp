#include "Bullet.h"
#include <QtMath>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet(QPointF startPos, double angle, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), angle(angle) {
    setPixmap(QPixmap(":/image/charge1.png").scaled(10, 10)); // Масштабируем изображение снаряда
    setRotation(angle);
    setPos(startPos);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);
    qDebug() << "Bullet created at position:" << startPos << "angle:" << angle;
}

Bullet::~Bullet() {
    qDebug() << "Bullet destroyed";
}

void Bullet::move() {
    double radians = qDegreesToRadians(angle);
    int dx = static_cast<int>(20 * qCos(radians));
    int dy = static_cast<int>(20 * qSin(radians));
    setPos(x() + dx, y() + dy);

    if (qAbs(x()) > 200 || qAbs(y()) > 200) {
        qDebug() << "Bullet deleted at position:" << pos();
        scene()->removeItem(this);
        delete this;
    }
}
