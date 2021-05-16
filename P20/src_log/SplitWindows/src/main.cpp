#include "windowTX.h"
#include "windowRX.h"

#include <QApplication>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    WindowTX txWindow;
    WindowRX rxWindow;

    txWindow.show();
    rxWindow.show();

    return app.exec();
}
