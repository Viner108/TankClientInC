#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Bullet(int startX, int startY, int angle);

public slots:
    void move();

private:
    int angle;
    QTimer* timer;
};

#endif // BULLET_H
