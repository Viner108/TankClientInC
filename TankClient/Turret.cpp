#include "Turret.h"

Turret::Turret(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), rotationAngle(0) {
    setPixmap(QPixmap(":/image/torre1.png").scaled(25, 25)); // Масштабируем изображение башни
    setTransformOriginPoint(boundingRect().center()); // Устанавливаем центр поворота башни
}

void Turret::rotate(int angle) {
    rotationAngle += angle;
    if (rotationAngle >= 360) rotationAngle -= 360;
    if (rotationAngle < 0) rotationAngle += 360;
    setRotation(rotationAngle);
}
