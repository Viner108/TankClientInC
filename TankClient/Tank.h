#ifndef TANK_H
#define TANK_H

#include <QWidget>
#include <QPixmap>

class Tank : public QWidget {
    Q_OBJECT

public:
    Tank(QWidget* parent = nullptr);
    void setPosition(int x, int y);
    void moveTank(int dx, int dy);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int x;
    int y;
    QPixmap tankImage;
};

#endif // TANK_H
