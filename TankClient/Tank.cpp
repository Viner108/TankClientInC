#include "Tank.h"
#include "Bullet.h"
#include <QPainter>
#include <QDebug>
#include <QtMath>

const int turretOffsetX = +30; // Смещение по оси X (скорректируем позже)
const int turretOffsetY = +20;  // Смещение по оси Y (скорректируем позже)

Tank::Tank(QWidget* parent)
    : QWidget(parent), x(0), y(0), rotationAngle(0), turretRotationAngle(0),
    tankImage(":/image/tankActive1.png"), turretImage(":/image/torre1.png") { // Используем путь к вашему изображению из ресурсов
    if (tankImage.isNull()) {
        qDebug() << "Failed to load tank image!";
    }
    if (turretImage.isNull()) {
        qDebug() << "Failed to load turret image!";
    }
    setFixedSize(tankImage.size());
}

void Tank::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    move(x, y); // Обновляем положение виджета
}

void Tank::moveTank(int dx, int dy) {
    // Преобразуем dx и dy в зависимости от текущего угла поворота
    double radians = qDegreesToRadians(static_cast<double>(rotationAngle));
    int newX = static_cast<int>(x + dx * qCos(radians) - dy * qSin(radians));
    int newY = static_cast<int>(y + dx * qSin(radians) + dy * qCos(radians));

    x = newX;
    y = newY;
    move(x, y); // Обновляем положение виджета
}

void Tank::rotateTank(int angle) {
    rotationAngle += angle;
    if (rotationAngle >= 360) {
        rotationAngle -= 360;
    }
    else if (rotationAngle < 0) {
        rotationAngle += 360;
    }
    update(); // Перерисовываем виджет
}

void Tank::rotateTurret(int angle) {
    turretRotationAngle += angle;
    if (turretRotationAngle >= 360) {
        turretRotationAngle -= 360;
    }
    else if (turretRotationAngle < 0) {
        turretRotationAngle += 360;
    }
    update(); // Перерисовываем виджет
}

void Tank::shoot() {
    double radians = qDegreesToRadians(static_cast<double>(turretRotationAngle));
    // Рассчитаем начальные координаты снаряда относительно центра башни
    int turretCenterX = x + width() / 2;
    int turretCenterY = y + height() / 2;
    int turretLength = turretImage.height(); // Предполагаем, что длина пушки равна высоте изображения башни

    // Скорректируем начальные координаты для снаряда
    int bulletX = turretCenterX + static_cast<int>((turretLength / 2) * qCos(radians));
    int bulletY = turretCenterY + static_cast<int>((turretLength / 2) * qSin(radians));
    Bullet* bullet = new Bullet(bulletX, bulletY, turretRotationAngle, this->parentWidget());
    bullet->show();
}

void Tank::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2); // Перемещаем начало координат в центр виджета

    // Отрисовка корпуса танка
    painter.save();
    painter.rotate(rotationAngle); // Поворачиваем корпус
    painter.translate(-width() / 2, -height() / 2); // Возвращаем начало координат на место
    painter.drawPixmap(0, 0, tankImage); // Координаты (0, 0) внутри виджета
    painter.restore();

    // Отрисовка башни танка с масштабированием и смещением
    painter.save();
    painter.rotate(turretRotationAngle); // Поворачиваем башню
    painter.translate(-width() / 2 + turretOffsetX, -height() / 2 + turretOffsetY); // Центрируем башню с учетом масштаба и смещения
    painter.scale(0.5, 0.5); // Масштабируем башню
    painter.drawPixmap(0, 0, turretImage); // Координаты (0, 0) внутри виджета
    painter.restore();
}
