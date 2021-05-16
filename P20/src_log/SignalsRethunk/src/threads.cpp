#include "threads.h"

#include <QPoint>
#include <QColor>


using namespace std;



#define START_DRAW_CMD 'S'
#define DRAW_LINE_CMD 'D'
#define CLEAR_SCREEN_CMD 'X'
#define PEN_COLOUR_CMD 'P'



int Threads::exec() {

    while(1) {
        mut.lock();
    }
}



void Threads::parseDeserialize() {

}


void setBusPointers(char *cp, bool *bp) {

    mainBus = (char *)cp;
    bufferFull = (bool *)bp;
}




//clears the threads internal buffer
void Threads::clearTempBuffer() {

    for(int i=0; i<BUFFER_SIZE; i++) {
        tempBuf[i] = 0x00;
    }
}

//copys the data in the temporary buffer to the main buffer
void Threads::copyToBus() {

    mut.lock();
    memcpy(mainBuffer, (char *)tempBuf, BUFFER_SIZE);
    bufferFull = true;
    mut.unlock();
}

//copys the data in the temporary buffer to the main buffer
void Threads::copyFromBus() {

    mut.lock();
    memcpy((char *)tempBuf, mainBuffer, BUFFER_SIZE);
    bufferFull = false;
    mut.unlock();
}




//slots to implement the movement of data from the window to the data bus

void Threads::rxStartDraw(QPoint startPoint) {

    clearTempBuffer();

    tempBuf[0] = START_DRAW_CMD;        //set header packet

    int x = startPoint.x();
    int y = startPoint.y();

    for(int i=0; i<4; i++) {
        tempBuf[i + 1] = (x >> (8 * i)) & 0xFF;
        tempBuf[i + 5] = (y >> (8 * i)) & 0xFF;
    }

    copyToBus();
}

void Threads::rxDrawLine(QPoint endPoint) {

    clearTempBuffer();

    tempBuf[0] = DRAW_LINE_CMD;        //set header packet

    int x = endPoint.x();
    int y = endPoint.y();

    for(int i=0; i<4; i++) {
        tempBuf[i + 1] = (x >> (8 * i)) & 0xFF;
        tempBuf[i + 5] = (y >> (8 * i)) & 0xFF;
    }

    copyToBus();
}

void Threads::rxClearScreen() {

    clearTempBuffer();

    tempBuf[0] = CLEAR_SCREEN_CMD;        //set header packet

    copyToBus();
}

void Threads::rxPenColour(QColor pc) {

    clearTempBuffer();

    tempBuf[0] = PEN_COLOUR_CMD;        //set header packet

    int r = pc.red();
    int g = pc.green();
    int b = pc.blue();

    tempBuf[1] = (char)r;
    tempBuf[2] = (char)g;
    tempBuf[3] = (char)b;

    copyToBus();
}