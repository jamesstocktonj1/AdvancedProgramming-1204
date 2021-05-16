#include "window.h"

#include <QPainter>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

#include <QMenu>
#include <QMenuBar>
#include <QLayout>


#include <map>
#include <vector>

using namespace std;

Window::Window(QWidget *parent) : QWidget(parent)
{
    //setup canvas
    setFixedSize(400,600);
    setWindowTitle("Network Whiteboard");

    QVBoxLayout *boxLayout = new QVBoxLayout(this);

    //setup menubar
    QMenuBar *mainMenu = new QMenuBar();

    //clear screen button
    QAction *menuClear = mainMenu->addAction("Clear");
    connect(menuClear, SIGNAL(triggered()), this, SLOT(setClearScreen()));

    //pen color menu
    QMenu *penColorMenu = new QMenu("Pen Color");

    QAction *blackColor = penColorMenu->addAction("Black");
    QAction *redColor = penColorMenu->addAction("Red");
    QAction *greenColor = penColorMenu->addAction("Green");
    QAction *blueColor = penColorMenu->addAction("Blue");

    //connect(blackColor, SIGNAL(triggered()), [this]() {setPenColor(Qt::black); });
    //connect(redColor, SIGNAL(triggered()), [this]() {setPenColor(Qt::red); });
    //connect(greenColor, SIGNAL(triggered()), [this]() {setPenColor(Qt::green); });
    //connect(blueColor, SIGNAL(triggered()), [this]() {setPenColor(Qt::blue); });

    mainMenu->addMenu(penColorMenu);

    //QMenu penSizeMenu = new QMenu("Pen Size");

    this->layout()->setMenuBar(mainMenu);

    

    //setup pen
    pen.setWidth(4);
    pen.setColor(penColor);

    //setup image canvas
    image = QImage(400, 600, QImage::Format_RGB32);
    image.fill(Qt::white);
}

void Window::setWindowName(const QString &name) {
    setWindowTitle(name);
}


void Window::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QRect rect = event->rect();

    painter.drawImage(rect, image, rect);
}



void Window::mousePressEvent(QMouseEvent * event) {

    //if left click button is pressed then start drawing
    if(event->button() == Qt::LeftButton) {
        prevPoint = event->pos();
        curDrawing = true;
    }

}

void Window::mouseMoveEvent(QMouseEvent * event) {

    //check if still drawing when button pressed
    if((event->buttons() & Qt::LeftButton) && curDrawing) {
        //joinPoints(event->pos());

        qDebug() << "Mouse X: " << event->pos().x() << "\tY: " << event->pos().y();

        if(txWindow) {
            s.serialiseCoord(prevPoint, point1);
            s.serialiseCoord(event->pos(), point2);
        }

        

        setDrawLine();
        prevPoint = event->pos();
    }

}

void Window::mouseReleaseEvent(QMouseEvent * event) {
    
    //if currently drawing and mouse button released
    if((event->button() == Qt::LeftButton) && curDrawing) {
        //joinPoints(event->pos());
        curDrawing = false;
    }
}


void Window::joinPoints(const QPoint &endPoint) {

    QPainter painter(&image);
    QPen p;

    p.setWidth(4);
    p.setColor(penColor);

    painter.setPen(p);                        //sets pen colour/size
    painter.drawLine(prevPoint, endPoint);      //join points

    update(QRect(prevPoint, endPoint).normalized().adjusted(-5, -5, 5, 5));     //update selected area

    prevPoint = endPoint;                       //joins up to next point
}





/*
//implement signals and slots
void Window::setDrawLine(const QPoint &startPoint, const QPoint &endPoint) {

    //draw line
    QPainter painter(&image);
    QPen p;

    p.setWidth(4);
    p.setColor(penColor);

    painter.setPen(p);                        //sets pen colour/size
    painter.drawLine(startPoint, endPoint);      //join points

    update(QRect(startPoint, endPoint).normalized().adjusted(-5, -5, 5, 5));     //update selected area
    
    emit sendDrawLine(startPoint, endPoint);
}*/

void Window::setDrawLine() {
    //draw line
    QPainter painter(&image);
    QPen p;
    QPoint startPoint, endPoint;

    
    startPoint = s.deserialiseCoord(point1);
    endPoint = s.deserialiseCoord(point2);

    p.setWidth(4);
    p.setColor(penColor);

    painter.setPen(p);                        //sets pen colour/size
    painter.drawLine(startPoint, endPoint);      //join points


    update(QRect(startPoint, endPoint).normalized().adjusted(-5, -5, 5, 5));     //update selected area

    if(txWindow) {
        emit sendDrawLine();
    }
    
}

void Window::setClearScreen() {

    image.fill(Qt::white);
    update();

    emit sendClearScreen();
}


void Window::setPenColour(QColor pc) {
    penColor = pc;

    emit sendPenColour(pc);
}



void Window::setTxWindow() {

    txWindow = true;
}