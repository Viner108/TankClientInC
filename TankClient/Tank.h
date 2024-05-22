#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Turret.h"

class Tank : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Tank(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;

private:
    int rotationAngle; // ”гол поворота танка
    Turret* turret;

    void shoot();
};

#endif // TANK_H
