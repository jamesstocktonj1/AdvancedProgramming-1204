#include "threads.h"

#include <QPoint>
#include <QColor>


using namespace std;



#define START_DRAW_CMD 'S'
#define DRAW_LINE_CMD 'D'
#define CLEAR_SCREEN_CMD 'X'
#define PEN_COLOUR_CMD 'P'


void Threads::run() {
    exec();
}

int Threads::exec() {

    while(1) {

        //if internal buffer is full
        if(dataToSend && !(*bufferFull)) {

            copyToBus();
            while(*bufferFull);
        }

        if(*bufferFull) {

            copyFromBus();
            parseDeserialize();
        }
        usleep(1);
    }
}


//parses data in the local buffer and emits the relevant signal
void Threads::parseDeserialize() {

    //handle the tx/rxStartDraw
    if(rxBuf[0] == START_DRAW_CMD) {
        int x = 0;
        int y = 0;

        for(int i=0; i<4; i++) {
            x += (rxBuf[i + 1] << (8 * i));
            y += (rxBuf[i + 5] << (8 * i));
        }
        emit txStartDraw(QPoint(x, y));
    }

    //handle the tx/rxDrawLine
    else if(rxBuf[0] == DRAW_LINE_CMD) {
        int x = 0;
        int y = 0;

        for(int i=0; i<4; i++) {
            x += (rxBuf[i + 1] << (8 * i));
            y += (rxBuf[i + 5] << (8 * i));
        }
        emit txDrawLine(QPoint(x, y));
    }

    //handle the tx/rxClearScreen
    else if(rxBuf[0] == CLEAR_SCREEN_CMD) {
        emit txClearScreen();
    }

    //handle the tx/rxPenColour
    else if(rxBuf[0] == PEN_COLOUR_CMD) {
        int r = rxBuf[1];
        int g = rxBuf[2];
        int b = rxBuf[3];

        emit txPenColour(QColor(r, g, b));
    }
}


void Threads::setBusPointers(char *cp, bool *bp) {

    mainBus = cp;
    bufferFull = bp;
}




//clears the threads internal buffer
void Threads::clearTempBuffer() {

    memset((char *)txBuf, 0x00, BUFFER_SIZE);
}

//copys the data in the temporary buffer to the main buffer
void Threads::copyToBus() {

    mut.lock();
    memcpy(mainBus, (char *)txBuf, BUFFER_SIZE);
    *bufferFull = true;
    mut.unlock();
}

//copys the data in the temporary buffer to the main buffer
void Threads::copyFromBus() {

    mut.lock();
    memcpy((char *)rxBuf, mainBus, BUFFER_SIZE);
    *bufferFull = false;
    mut.unlock();
}




//slots to implement the movement of data from the window to the data bus

//handles the incoming slot for the start draw command
void Threads::rxStartDraw(QPoint startPoint) {

    clearTempBuffer();

    txBuf[0] = START_DRAW_CMD;        //set header packet

    int x = startPoint.x();
    int y = startPoint.y();

    for(int i=0; i<4; i++) {
        txBuf[i + 1] = (x >> (8 * i)) & 0xFF;
        txBuf[i + 5] = (y >> (8 * i)) & 0xFF;
    }

    dataToSend = true;
}




void Threads::rxDrawLine(QPoint endPoint) {

    clearTempBuffer();

    txBuf[0] = DRAW_LINE_CMD;        //set header packet

    int x = endPoint.x();
    int y = endPoint.y();

    for(int i=0; i<4; i++) {
        txBuf[i + 1] = (x >> (8 * i)) & 0xFF;
        txBuf[i + 5] = (y >> (8 * i)) & 0xFF;
    }

    dataToSend = true;
}

void Threads::rxClearScreen() {

    clearTempBuffer();

    txBuf[0] = CLEAR_SCREEN_CMD;        //set header packet

    dataToSend = true;
}

void Threads::rxPenColour(QColor pc) {

    clearTempBuffer();

    txBuf[0] = PEN_COLOUR_CMD;        //set header packet

    int r = pc.red();
    int g = pc.green();
    int b = pc.blue();

    txBuf[1] = (char)r;
    txBuf[2] = (char)g;
    txBuf[3] = (char)b;

    dataToSend = true;
}