#include "Tank.h"
#include <QPainter>
#include <QDebug>

Tank::Tank(QWidget* parent)
    : QWidget(parent), x(100), y(100), tankImage(":/image/tankActive.png") { // ���������� ���� � ������ ����������� �� ��������
    if (tankImage.isNull()) {
        qDebug() << "Failed to load tank image!";
    }
    setFixedSize(tankImage.size());
}

void Tank::move(int dx, int dy) {
    x += dx;
    y += dy;
    update();
}

void Tank::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, tankImage); // ���������� (0, 0) ������ �������
}
