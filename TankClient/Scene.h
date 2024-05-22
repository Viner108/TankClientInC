#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "Tank.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene(QObject* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;

protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override;

private:
    Tank* tank;
};

#endif // SCENE_H
