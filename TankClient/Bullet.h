#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include <QPixmap>

class Bullet : public QWidget {
    Q_OBJECT

public:
    Bullet(int startX, int startY, int angle, QWidget* parent = nullptr);
    void moveBullet();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int x;
    int y;
    int angle; // Угол движения снаряда
    QPixmap bulletImage;
};

#endif // BULLET_H
