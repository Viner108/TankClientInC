#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "Tank.h"

class Scene : public QWidget {
    Q_OBJECT

public:
    Scene(QWidget* parent = nullptr);
    void setTank(Tank* tank);

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    Tank* tank;
};

#endif // SCENE_H
