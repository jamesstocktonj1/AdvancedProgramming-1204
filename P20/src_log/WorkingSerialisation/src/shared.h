#ifndef SHARED_H
#define SHARED_H

#include <QPoint>
#include <QDebug>

using namespace std;



//char point1[9] = {0x00, };
//char point2[9] = {0x00, };



class Shared {

public:
    Shared();

    void serialiseCoord(QPoint p, char *d);
    QPoint deserialiseCoord(char *p);
    
    

    

private:




};





#endif