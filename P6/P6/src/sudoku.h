#ifndef SUDOKU_H
#define SUDOKU_H


#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//one side of the grid (default 9)
#define GRID_SIZE 9

//sub grid size (default 3)
#define SGRID_SIZE 3

struct cell {
    bool solved = false;                    //true if original value or solved by algorithm
    int solvedVal = 0;
    int numSolutions = 0;
    int vals[GRID_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};    //1 if it is a possible value (anything is possible by default)
};

/*
//sudoku grid 2d array       row, column
cell sudokuGrid[GRID_SIZE][GRID_SIZE];

bool zerError = false;


void fileToGrid(const char * fileName);
void displayBoard(void);


bool isSolved(int row, int column);
void handleSolution(int row, int column);

bool solveGrid(void);

void deleteFromRow(int row, int num);
void deleteFromColumn(int column, int num);
void deleteFromSubcell(int row, int column, int num);
*/



class Sudoku {
public:
    Sudoku() {

    }

    int solveSudoku();

    void fileToGrid(const char * fileName);
    void displayBoard(void);

    int getCell(int row, int column);
    void setCell(int row, int column, int num);

    bool isSolved(int row, int column);
    void handleSolution(int row, int column);

    bool solveGrid(void);

    void deleteFromRow(int row, int num);
    void deleteFromColumn(int column, int num);
    void deleteFromSubcell(int row, int column, int num);

    cell sudokuGrid[GRID_SIZE][GRID_SIZE];
    bool zerError = false;
};

#endif