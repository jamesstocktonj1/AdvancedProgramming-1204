#ifndef WINDOWRX_H
#define WINDOWRX_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>
#include <vector>
#include <map>

using namespace std;

class WindowRX : public QWidget
{
    Q_OBJECT

public:
    WindowRX(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) override;

    void joinPoints(const QPoint & startPoint, const QPoint &endPoint);

    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

private:
    bool curDrawing = false;            

    QColor penColor = Qt::black;
    QImage image;
    QPoint prevPoint;
    QPen pen;

};

#endif
