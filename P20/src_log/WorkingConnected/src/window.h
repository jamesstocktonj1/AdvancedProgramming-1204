#ifndef WINDOW_H
#define WINDOW_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>
#include <vector>
#include <map>

using namespace std;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    
    void setWindowName(const QString &name);

protected:
    void paintEvent(QPaintEvent *event) override;    

    void joinPoints(const QPoint &endPoint);

    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    void clearScreen();

public slots:
    void setDrawLine(const QPoint &startPoint, const QPoint &endPoint);
    void setClearScreen();
    void setPenColour(QColor pc);

signals:
    void sendDrawLine(const QPoint &startPoint, const QPoint &endPoint);
    void sendClearScreen();
    void sendPenColour(QColor pc);

private:
    bool curDrawing = false;            

    QColor penColor = Qt::black;
    QImage image;
    QPoint prevPoint;
    QPen pen;

};

#endif
