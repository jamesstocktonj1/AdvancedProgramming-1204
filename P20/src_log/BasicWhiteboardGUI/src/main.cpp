#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);
    Window window;
    window.show();

    Window win2;
    win2.show();
    return app.exec();
}
