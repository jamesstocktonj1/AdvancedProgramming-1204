#include "window.h"
#include "threads.h"

#include <QApplication>
#include <QWidget>



int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    Window a, b;
    Threads ta, tb;

    //Window A -> Thread A
    QWidget::connect(&a, SIGNAL(txStartDraw(QPoint)), &ta, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&a, SIGNAL(txDrawLine(QPoint)), &ta, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&a, SIGNAL(txClearScreen()), &ta, SLOT(rxClearScreen()));
    QWidget::connect(&a, SIGNAL(txPenColour(QColor)), &ta, SLOT(rxPenColour(QColor)));

    //Thread A -> Window A
    QWidget::connect(&ta, SIGNAL(txStartDraw(QPoint)), &a, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&ta, SIGNAL(txDrawLine(QPoint)), &a, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&ta, SIGNAL(txClearScreen()), &a, SLOT(rxClearScreen()));
    QWidget::connect(&ta, SIGNAL(txPenColour(QColor)), &a, SLOT(rxPenColour(QColor)));


    //Window B -> Thread B
    QWidget::connect(&b, SIGNAL(txStartDraw(QPoint)), &tb, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&b, SIGNAL(txDrawLine(QPoint)), &tb, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&b, SIGNAL(txClearScreen()), &tb, SLOT(rxClearScreen()));
    QWidget::connect(&b, SIGNAL(txPenColour(QColor)), &tb, SLOT(rxPenColour(QColor)));

    //Thread B -> Window B
    QWidget::connect(&tb, SIGNAL(txStartDraw(QPoint)), &b, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&tb, SIGNAL(txDrawLine(QPoint)), &b, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&tb, SIGNAL(txClearScreen()), &b, SLOT(rxClearScreen()));
    QWidget::connect(&tb, SIGNAL(txPenColour(QColor)), &b, SLOT(rxPenColour(QColor)));


    //old local interconnects (threadless)
    //QWidget::connect(&a, SIGNAL(txStartDraw(QPoint)), &b, SLOT(rxStartDraw(QPoint)));
    //QWidget::connect(&a, SIGNAL(txDrawLine(QPoint)), &b, SLOT(rxDrawLine(QPoint)));
    //QWidget::connect(&a, SIGNAL(txClearScreen()), &b, SLOT(rxClearScreen()));
    //QWidget::connect(&a, SIGNAL(txPenColour(QColor)), &b, SLOT(rxPenColour(QColor)));

    //QWidget::connect(&b, SIGNAL(txStartDraw(QPoint)), &a, SLOT(rxStartDraw(QPoint)));
    //QWidget::connect(&b, SIGNAL(txDrawLine(QPoint)), &a, SLOT(rxDrawLine(QPoint)));
    //QWidget::connect(&b, SIGNAL(txClearScreen()), &a, SLOT(rxClearScreen()));
    //QWidget::connect(&b, SIGNAL(txPenColour(QColor)), &a, SLOT(rxPenColour(QColor)));

    //initialize shared pointers (mainbus)
    bool *bufferFull;
    char *mainBuffer;

    bufferFull = (bool *)malloc(sizeof(bool));
    mainBuffer = (char *)malloc(sizeof(char) * 9);

    //initialize Thread A
    ta.setBusPointers(mainBuffer, (bool *)bufferFull);
    ta.start();

    //initialize Thread B
    tb.setBusPointers(mainBuffer, (bool *)bufferFull);
    tb.start();

    //initialize Window A
    a.setWindowName("Send Window");
    a.show();
    
    //initialize Window B
    b.setWindowName("Receive Window");
    b.show();

    //application main loop
    return app.exec();
}
