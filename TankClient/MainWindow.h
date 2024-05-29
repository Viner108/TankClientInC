#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "Scene.h"
#include <QTcpSocket>

struct BulletInfo {
    QPointF position;
    double angle;
};

// Операторы сериализации для BulletInfo
QDataStream& operator<<(QDataStream& out, const BulletInfo& bullet);
QDataStream& operator>>(QDataStream& in, BulletInfo& bullet);

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onServerResponse();

private:
    QGraphicsView* view;
    Scene* scene;
    QTcpSocket* socket;
};

#endif // MAINWINDOW_H
