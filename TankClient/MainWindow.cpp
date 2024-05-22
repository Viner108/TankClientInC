#include "MainWindow.h"
#include "Tank.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    scene = new Scene(this);
    view = new QGraphicsView(scene, this);
    setCentralWidget(view);

    scene->setSceneRect(0, 0, 800, 600);
    view->setFixedSize(800, 600);

    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow() {}
