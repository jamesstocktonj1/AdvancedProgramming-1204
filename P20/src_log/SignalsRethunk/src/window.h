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

    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;


private slots:
    void clearButtonCallback();

    void blackButtonCallback();
    void redButtonCallback();
    void greenButtonCallback();
    void blueButtonCallback();

public slots:
    void rxStartDraw(QPoint startPoint);
    void rxDrawLine(QPoint endPoint);
    void rxClearScreen();
    void rxPenColour(QColor pc);

signals:
    void txStartDraw(QPoint startPoint);
    void txDrawLine(QPoint endPoint);
    void txClearScreen();
    void txPenColour(QColor pc);

private:
    bool curDrawing = false;          

    QColor penColor = Qt::black;
    QImage image;
    QPoint prevPoint;
    QPen pen;
};

#endif
