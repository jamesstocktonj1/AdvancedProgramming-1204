#include "windowTX.h"

#include <QPainter>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

#include <map>
#include <vector>

using namespace std;

WindowTX::WindowTX(QWidget *parent) : QWidget(parent)
{
    //setup canvas
    setFixedSize(400,600);
    setWindowTitle("Network Whiteboard");

    //setup pen
    pen.setWidth(4);
    pen.setColor(penColor);

    //setup image canvas
    image = QImage(400, 600, QImage::Format_RGB32);
    image.fill(Qt::white);
}


void WindowTX::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QRect rect = event->rect();

    painter.drawImage(rect, image, rect);
}



void WindowTX::mousePressEvent(QMouseEvent * event) {

    //if left click button is pressed then start drawing
    if(event->button() == Qt::LeftButton) {
        prevPoint = event->pos();
        curDrawing = true;
    }

}

void WindowTX::mouseMoveEvent(QMouseEvent * event) {

    //check if still drawing when button pressed
    if((event->buttons() & Qt::LeftButton) && curDrawing) {
        joinPoints(event->pos());
    }

}

void WindowTX::mouseReleaseEvent(QMouseEvent * event) {
    
    //if currently drawing and mouse button released
    if((event->button() == Qt::LeftButton) && curDrawing) {
        joinPoints(event->pos());
        curDrawing = false;
    }
}


void WindowTX::joinPoints(const QPoint & startPoint, const QPoint &endPoint) {

    QPainter painter(&image);
    QPen p;

    p.setWidth(4);
    p.setColor(penColor);

    painter.setPen(p);                        //sets pen colour/size
    painter.drawLine(prevPoint, endPoint);      //join points

    update(QRect(prevPoint, endPoint).normalized().adjusted(-5, -5, 5, 5));     //update selected area

    prevPoint = endPoint;                       //joins up to next point
}