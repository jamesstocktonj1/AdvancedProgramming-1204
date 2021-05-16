#include "window.h"

#include <QPainter>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

#include <QMenu>
#include <QMenuBar>
#include <QLayout>



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
    connect(menuClear, SIGNAL(triggered()), this, SLOT(clearButtonCallback()));

    //pen colour menu
    QMenu *penColourMenu = new QMenu("Pen Colour");
    QAction *blackButton = penColourMenu->addAction("Black");
    QAction *redButton = penColourMenu->addAction("Red");
    QAction *greenButton = penColourMenu->addAction("Green");
    QAction *blueButton = penColourMenu->addAction("Blue");

    connect(blackButton, SIGNAL(triggered()), this, SLOT(blackButtonCallback()));
    connect(redButton, SIGNAL(triggered()), this, SLOT(redButtonCallback()));
    connect(greenButton, SIGNAL(triggered()), this, SLOT(greenButtonCallback()));
    connect(blueButton, SIGNAL(triggered()), this, SLOT(blueButtonCallback()));

    mainMenu->addMenu(penColourMenu);

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

        curDrawing = true;

        rxStartDraw(event->pos());
        emit txStartDraw(event->pos());
    }

}

void Window::mouseMoveEvent(QMouseEvent * event) {

    //check if still drawing when button pressed
    if((event->buttons() & Qt::LeftButton) && curDrawing) {

        rxDrawLine(event->pos());            //draws line local
        emit txDrawLine(event->pos());       //emits remote draw command
    }

}

void Window::mouseReleaseEvent(QMouseEvent * event) {
    
    //if currently drawing and mouse button released
    if((event->button() == Qt::LeftButton) && curDrawing) {

        curDrawing = false;

        rxDrawLine(event->pos());            //draws line local
        emit txDrawLine(event->pos());       //emits remote draw command
    }
}


void Window::rxStartDraw(QPoint startPoint) {

    prevPoint = startPoint;
}

void Window::rxDrawLine(QPoint endPoint) {

    QPainter painter(&image);
    QPen p;

    p.setWidth(4);
    p.setColor(penColor);

    painter.setPen(p);
    painter.drawLine(prevPoint, endPoint);

    update(QRect(prevPoint, endPoint).normalized().adjusted(-5, -5, 5, 5));

    rxStartDraw(endPoint);
    //prevPoint = endPoint;
}

void Window::rxClearScreen() {

    image.fill(Qt::white);
    update();
}

void Window::rxPenColour(QColor pc) {

    penColor = pc;
}

void Window::clearButtonCallback() {

    rxClearScreen();
    emit txClearScreen();
}


void Window::blackButtonCallback() {

    rxPenColour(Qt::black);
    emit txPenColour(Qt::black);
}

void Window::redButtonCallback(){

    rxPenColour(Qt::red);
    emit txPenColour(Qt::red);
}

void Window::greenButtonCallback(){

    rxPenColour(Qt::green);
    emit txPenColour(Qt::green);
}

void Window::blueButtonCallback() {

    rxPenColour(Qt::blue);
    emit txPenColour(Qt::blue);
}