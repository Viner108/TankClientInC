#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

class Scene : public QWidget {
    Q_OBJECT

public:
    Scene(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // SCENE_H