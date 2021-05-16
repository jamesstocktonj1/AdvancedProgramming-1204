#include "window.h"
#include "threads.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    Window a, b;
    QWidget::connect(&a, SIGNAL(txStartDraw(QPoint)), &b, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&a, SIGNAL(txDrawLine(QPoint)), &b, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&a, SIGNAL(txClearScreen()), &b, SLOT(rxClearScreen()));
    QWidget::connect(&a, SIGNAL(txPenColour(QColor)), &b, SLOT(rxPenColour(QColor)));

    QWidget::connect(&b, SIGNAL(txStartDraw(QPoint)), &a, SLOT(rxStartDraw(QPoint)));
    QWidget::connect(&b, SIGNAL(txDrawLine(QPoint)), &a, SLOT(rxDrawLine(QPoint)));
    QWidget::connect(&b, SIGNAL(txClearScreen()), &a, SLOT(rxClearScreen()));
    QWidget::connect(&b, SIGNAL(txPenColour(QColor)), &a, SLOT(rxPenColour(QColor)));

    a.setWindowName("Send Window");
    a.show();
    
    b.setWindowName("Receive Window");
    b.show();

    return app.exec();
}
