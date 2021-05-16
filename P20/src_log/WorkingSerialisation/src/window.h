#ifndef WINDOW_H
#define WINDOW_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>
#include <vector>
#include <map>

#include "shared.h"

using namespace std;

char point1[9] = {0x00, };
char point2[9] = {0x00, };

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    
    void setWindowName(const QString &name);
    void setTxWindow();

protected:
    void paintEvent(QPaintEvent *event) override;    

    void joinPoints(const QPoint &endPoint);

    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    void clearScreen();

public slots:
    void setDrawLine();
    void setClearScreen();
    void setPenColour(QColor pc);

signals:
    void sendDrawLine();
    void sendClearScreen();
    void sendPenColour(QColor pc);

private:
    bool curDrawing = false;       

    bool txWindow = false;     

    QColor penColor = Qt::black;
    QImage image;
    QPoint prevPoint;
    QPen pen;
    
    Shared s;

};

#endif
