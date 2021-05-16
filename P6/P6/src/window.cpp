#include "window.h"

#include <QPainter>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

#include <map>
#include <vector>

using namespace std;


Window::Window(QWidget *parent) : QWidget(parent)
{
   // set form size
   //setFixedSize(400,600);
   setWindowTitle("Sudoku Solver");

    //load default sudoku file
   sud.fileToGrid("SUDOKU.txt");
   sud.displayBoard();
}


void Window::paintEvent(QPaintEvent * event) {
    int boardPixelSize = 0;
    int cellPixelSize = 0;

    QSize screenSize = size();

    QPainter painter(this);
    QPen pen;
    QFont font;

    font.setPixelSize(30);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.setFont(font);

    cout << "Screen Size: " << screenSize.rheight() << ", " << screenSize.rwidth() << endl;

    //takes the smallest side (height, width) and makes it the size of the square
    if(screenSize.rheight() < screenSize.rwidth()) {
        boardPixelSize = screenSize.rheight();
    }
    else {
        boardPixelSize = screenSize.rwidth();
    }

    cellPixelSize = (int) boardPixelSize / 11;


    
    //draw board outline
    painter.drawLine(QPoint(cellPixelSize, cellPixelSize), QPoint(cellPixelSize *10, cellPixelSize));                   //horizontal top bar
    painter.drawLine(QPoint(cellPixelSize, cellPixelSize * 10), QPoint(cellPixelSize *10, cellPixelSize * 10));         //horizontal bottom bar


    painter.drawLine(QPoint(cellPixelSize, cellPixelSize), QPoint(cellPixelSize, cellPixelSize * 10));                  //vertical left bar
    painter.drawLine(QPoint(cellPixelSize * 10, cellPixelSize), QPoint(cellPixelSize *10, cellPixelSize * 10));         //vertical right bar



    //draw cell divider lines
    painter.drawLine(QPoint(cellPixelSize, cellPixelSize * 4), QPoint(cellPixelSize * 10, cellPixelSize * 4));          //draw horizontal lines
    painter.drawLine(QPoint(cellPixelSize, cellPixelSize * 7), QPoint(cellPixelSize * 10, cellPixelSize * 7));

    painter.drawLine(QPoint(cellPixelSize * 4, cellPixelSize), QPoint(cellPixelSize * 4, cellPixelSize * 10));          //draw vertical lines
    painter.drawLine(QPoint(cellPixelSize * 7, cellPixelSize), QPoint(cellPixelSize * 7, cellPixelSize * 10));



    //draw square boardSize / 11 - 1 square blank each side
    pen.setWidth(2);
    painter.setPen(pen);

    for(int i=2; i<10; i++) {
        //draw horizontal line

        painter.drawLine(cellPixelSize, cellPixelSize * i, cellPixelSize * 10, cellPixelSize * i);                      //draw horizontal grid lines

        painter.drawLine(cellPixelSize * i, cellPixelSize, cellPixelSize * i, cellPixelSize * 10);                      //draw vertical grid lines


    }


    //draw the numbers in the squares just created

    //increment row (y)
    for(int i=0; i<9; i++) {

        //increment column (x)
        for(int j=0; j<9; j++) {
            int num = sud.getCell(i, j);

            if(num != 0) {
                //draw number to grid
                painter.drawText((1.25 * cellPixelSize) + (j * cellPixelSize), (1.75 * cellPixelSize) + (i * cellPixelSize), QString().setNum(num));
            }
        }
    }
}

void Window::mouseReleaseEvent(QMouseEvent * event) 
{
    // get click position
    //qDebug() << "Mouse x " << event->x() << " Mouse y " << event->y();

    int winMin, winMax, cellPixelSize;
    int mouseX, mouseY;
    int cellX, cellY;


    //get cell and board size to work out mouse clicks
    QSize screenSize = size();

    if(screenSize.rheight() < screenSize.rwidth()) {
        cellPixelSize = (int) screenSize.rheight() / 11;
    }
    else {
        cellPixelSize = (int) screenSize.rwidth() / 11;
    }

    winMin = cellPixelSize;
    winMax = (int) cellPixelSize * 10;


    mouseX = (int) event->x();
    mouseY = (int) event->y();


    if((winMin < mouseX) && (mouseX < winMax) && (winMin < mouseY) && (mouseY < winMax)) {
        

        cellX = (mouseX / cellPixelSize) - 1;
        cellY = (mouseY / cellPixelSize) - 1;
        
        qDebug() << "Mouse in cell " << cellX << "," << cellY;


        //row (y), collumn(x)
        int num = sud.getCell(cellY, cellX);

        if(num > 8) {
            num = 0;
        }
        else {
            num++;
        }

        qDebug() << "New Num: " << num;

        sud.setCell(cellY, cellX, (int)num);

        update();
    }
    
}
