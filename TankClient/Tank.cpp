#include "Tank.h"
#include <QPainter>
#include <QDebug>

Tank::Tank(QWidget* parent)
    : QWidget(parent), x(0), y(0), tankImage(":/image/tankActive.png") { // Используем путь к вашему изображению из ресурсов
    if (tankImage.isNull()) {
        qDebug() << "Failed to load tank image!";
    }
    setFixedSize(tankImage.size());
}

void Tank::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    move(x, y); // Обновляем положение виджета
}

void Tank::moveTank(int dx, int dy) {
    x += dx;
    y += dy;
    move(x, y); // Обновляем положение виджета
}

void Tank::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, tankImage); // Координаты (0, 0) внутри виджета
}
