#include "MainWindow.h"
#include "Scene.h"
#include "Tank.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    Scene* scene = new Scene(this);
    setCentralWidget(scene);

    Tank* tank = new Tank(scene);
    scene->setTank(tank);
    tank->setPosition(200, 200); // Установите координаты, чтобы танк был виден на сцене
}

MainWindow::~MainWindow() {}
