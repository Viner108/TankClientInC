#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Bullet(QPointF startPos, double angle, QGraphicsItem* parent = nullptr);
    ~Bullet(); // Добавим деструктор для отладки

public slots:
    void move();

private:
    double angle;
    QTimer* timer;
};

#endif // BULLET_H
