#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Turret : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Turret(QGraphicsItem* parent = nullptr);
    void rotate(int angle);

private:
    int rotationAngle;
};

#endif // TURRET_H
