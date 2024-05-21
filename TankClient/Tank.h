#ifndef TANK_H
#define TANK_H

#include <QWidget>
#include <QPixmap>
#include "Bullet.h"

class Tank : public QWidget {
    Q_OBJECT

public:
    Tank(QWidget* parent = nullptr);
    void setPosition(int x, int y);
    void moveTank(int dx, int dy);
    void rotateTank(int angle);
    void rotateTurret(int angle);
    void shoot();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int x;
    int y;
    int rotationAngle; // ”гол поворота танка
    int turretRotationAngle; // ”гол поворота башни
    QPixmap tankImage;
    QPixmap turretImage;
};

#endif // TANK_H
