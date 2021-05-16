#include "window.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    Window a, b;
    QWidget::connect(&a, SIGNAL(sendDrawLine(QPoint, QPoint)), &b, SLOT(setDrawLine(QPoint, QPoint)));      //connect draw lines
    QWidget::connect(&a, SIGNAL(sendClearScreen()), &b, SLOT(setClearScreen()));                            //connect clear screen
    QWidget::connect(&a, SIGNAL(sendPenColour(QColor)), &b, SLOT(setPenColour(QColor)));                    //connect pen colour

    a.setWindowName("Send Window");
    a.show();
    
    b.setWindowName("Receive Window");
    b.show();

    return app.exec();
}
