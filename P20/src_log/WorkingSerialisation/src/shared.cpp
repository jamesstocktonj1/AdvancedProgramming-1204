#include "shared.h"






Shared::Shared() {

}





void Shared::serialiseCoord(QPoint p, char *d) {
    int x = p.x();
    int y = p.y();
    
    for(int i=0; i<4; i++) {
        d[i + 1] = (x >> (8 * i)) & 0xFF;
        d[i + 5] = (y >> (8 * i)) & 0xFF;
    }

/*
    qDebug() << "Ser: ";
    for(int i=0; i<8; i++) {
        qDebug() << d[i];
    }*/
}


QPoint Shared::deserialiseCoord(char *d) {
    int x = 0, y = 0;

    for(int i=0; i<4; i++) {
        x += (d[i + 1] << (8 * i));
        y += (d[i + 5] << (8 * i));
    }

    qDebug() << "Deser X: " <<  x << "\tY: " << y;

    return QPoint(x, y);
}