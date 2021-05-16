#ifndef THREADS_H
#define THREADS_H


#include <QThread>
#include <QMutex>

#include <QPoint>
#include <QColor>

using namespace std;

#define BUFFER_SIZE 9



#ifndef VAR_H
#define VAR_H
//char *mainBuffer[BUFFER_SIZE] = {0x00, };
//bool bufferFull = false;
#endif




#define START_DRAW_CMD 'S'
#define DRAW_LINE_CMD 'D'
#define CLEAR_SCREEN_CMD 'X'
#define PEN_COLOUR_CMD 'P'



class Threads : public QThread {
    Q_OBJECT

public:

    void exec() override;

    void parseDeserialize();

    void clearTempBuffer();
    void copyToBus();
    void copyFromBus();

    void setBusPointers(char *cp, bool *bp);


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
    QMutex mut;
    char tempBuf[BUFFER_SIZE] = {0x00, };

    char *mainBus;
    bool *bufferFull;
};




#endif