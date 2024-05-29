#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Turret.h"

class Tank : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Tank(QGraphicsItem* parent = nullptr);
    void updateTurretRotation(int angle);

private:
    int rotationAngle; // Угол поворота танка
    Turret* turret;
};

#endif // TANK_H
