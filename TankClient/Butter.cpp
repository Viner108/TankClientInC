#include "Bullet.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>

Bullet::Bullet(int startX, int startY, int angle, QWidget* parent)
    : QWidget(parent), x(startX), y(startY), angle(angle), bulletImage(":/image/charge1.png") {
    if (bulletImage.isNull()) {
        qDebug() << "Failed to load bullet image!";
    }
    setFixedSize(bulletImage.size() / 3); // ��������� ������ ������� � 3 ����
    move(x, y);

    // ������ ������� ��� �������� �������
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBullet);
    timer->start(50); // ������ 50 ��
}

void Bullet::moveBullet() {
    double radians = qDegreesToRadians(static_cast<double>(angle));
    x += static_cast<int>(20 * qCos(radians)); // ����������� �������� � 2 ����
    y += static_cast<int>(20 * qSin(radians)); // ����������� �������� � 2 ����
    move(x, y);

    // �������� �������, ���� �� ������ 200 ��������
    if (qAbs(x - pos().x()) > 200 || qAbs(y - pos().y()) > 200) {
        delete this;
    }
}

void Bullet::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2); // ���������� ������ ��������� � ����� �������
    painter.rotate(angle); // ������������ ������ �� ������ ����
    painter.translate(-width() / 2, -height() / 2); // ���������� ������ ��������� �� �����
    painter.scale(1.0 / 3, 1.0 / 3); // ������������ ������ � 3 ����
    painter.drawPixmap(0, 0, bulletImage);
}
