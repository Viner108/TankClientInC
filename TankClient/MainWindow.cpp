#include "MainWindow.h"
#include "Tank.h"
#include "Bullet.h"
#include <QHostAddress>
#include <QDataStream>
#include <QDebug>

QDataStream& operator<<(QDataStream& out, const BulletInfo& bullet) {
    out << bullet.position << bullet.angle;
    return out;
}

QDataStream& operator>>(QDataStream& in, BulletInfo& bullet) {
    in >> bullet.position >> bullet.angle;
    return in;
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), socket(new QTcpSocket(this)) {
    scene = new Scene(this);
    view = new QGraphicsView(scene, this);
    setCentralWidget(view);

    scene->setSceneRect(0, 0, 800, 600);
    view->setFixedSize(800, 600);

    setFocusPolicy(Qt::StrongFocus);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onServerResponse);
    socket->connectToHost(QHostAddress::LocalHost, 1234); // Используйте нужный порт

    // Передаем ссылку на сокет в сцену
    scene->setSocket(socket);
}

MainWindow::~MainWindow() {}

void MainWindow::onServerResponse() {
    QByteArray data = socket->readAll();
    QDataStream in(data);
    QPointF newPos;
    int newAngle;
    int newTurretAngle;
    QList<BulletInfo> bullets;
    in >> newPos >> newAngle >> newTurretAngle >> bullets;

    qDebug() << "Received new position from server: position =" << newPos << "rotationAngle =" << newAngle << "turretRotationAngle =" << newTurretAngle;

    // Обновляем положение и угол поворота танка
    scene->updateTankPosition(newPos, newAngle, newTurretAngle);

    // Очищаем старые снаряды
    scene->clearBullets();

    // Обновляем снаряды
    for (const BulletInfo& bullet : bullets) {
        qDebug() << "Adding bullet at position:" << bullet.position << "angle:" << bullet.angle;
        Bullet* b = new Bullet(bullet.position, bullet.angle);
        scene->addItem(b);
        b->setPos(bullet.position);
    }
}
