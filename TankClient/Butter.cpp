#include "Bullet.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>

Bullet::Bullet(int startX, int startY, int angle, QWidget* parent)
    : QWidget(parent), x(startX), y(startY), angle(angle), bulletImage(":/image/charge1.png") {
    if (bulletImage.isNull()) {
        qDebug() << "Failed to load bullet image!";
    }
    setFixedSize(bulletImage.size() / 3); // Уменьшаем размер виджета в 3 раза
    move(x, y);

    // Запуск таймера для движения снаряда
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBullet);
    timer->start(50); // Каждые 50 мс
}

void Bullet::moveBullet() {
    double radians = qDegreesToRadians(static_cast<double>(angle));
    x += static_cast<int>(20 * qCos(radians)); // Увеличиваем скорость в 2 раза
    y += static_cast<int>(20 * qSin(radians)); // Увеличиваем скорость в 2 раза
    move(x, y);

    // Удаление снаряда, если он прошел 200 пикселей
    if (qAbs(x - pos().x()) > 200 || qAbs(y - pos().y()) > 200) {
        delete this;
    }
}

void Bullet::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2); // Перемещаем начало координат в центр виджета
    painter.rotate(angle); // Поворачиваем снаряд на нужный угол
    painter.translate(-width() / 2, -height() / 2); // Возвращаем начало координат на место
    painter.scale(1.0 / 3, 1.0 / 3); // Масштабируем снаряд в 3 раза
    painter.drawPixmap(0, 0, bulletImage);
}
