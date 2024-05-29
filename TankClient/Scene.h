#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "Tank.h"
#include <QTcpSocket>

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene(QObject* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    void updateTankPosition(const QPointF& position, int angle, int turretAngle);
    void setSocket(QTcpSocket* socket);
    void clearBullets();

private:
    Tank* tank;
    QTcpSocket* socket;
};

#endif // SCENE_H
