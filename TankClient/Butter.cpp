#include "Bullet.h"
#include <QTimer>
#include <QtMath>
#include <QGraphicsScene>

Bullet::Bullet(int startX, int startY, int angle)
    : angle(angle) {
    setPixmap(QPixmap(":/image/charge1.png").scaled(10, 10)); // Масштабируем изображение снаряда
    setRotation(angle);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);
}

void Bullet::move() {
    double radians = qDegreesToRadians(static_cast<double>(angle));
    int dx = static_cast<int>(20 * qCos(radians));
    int dy = static_cast<int>(20 * qSin(radians));
    setPos(x() + dx, y() + dy);

    if (qAbs(x() - pos().x()) > 200 || qAbs(y() - pos().y()) > 200) {
        scene()->removeItem(this);
        delete this;
    }
}
