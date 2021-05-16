#ifndef WINDOWTX_H
#define WINDOWTX_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>
#include <vector>
#include <map>

using namespace std;

class WindowTX : public QWidget
{
    Q_OBJECT

public:
    WindowTX(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) override;

    void joinPoints(const QPoint & startPoint, const QPoint &endPoint);
    void sendPoints(const QPoint)

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
