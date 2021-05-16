#include "sudoku.h"



int Sudoku::solveSudoku() {


    displayBoard();

    int totalSolutions = 0;
    int newSolutions = 5;


    if(solveGrid()) {
        displayBoard();
        cout << "FINAL SOLUTION\n";
        return 1;
    }
    else {
        displayBoard();
        cout << "Initial Pass Failes\n";
    }



    cell savedGrid[GRID_SIZE][GRID_SIZE];

    memcpy(savedGrid, sudokuGrid, sizeof(sudokuGrid));      //save the last status of the solved grid


    //perform combination solve
    for(int row=0; row<GRID_SIZE; row++) {

        for(int column=0; column<GRID_SIZE; column++) {

            //finds the not solved cells
            if(!sudokuGrid[row][column].solved) {

                for(int x=0; x<GRID_SIZE; x++) {
                    
                    //if its a possible value
                    if(savedGrid[row][column].vals[x] == 1) {

                        //reset grid to last know good point
                        memcpy(sudokuGrid, savedGrid, sizeof(savedGrid));

                        sudokuGrid[row][column].solvedVal = (x + 1);
                        sudokuGrid[row][column].solved = true;

                        //test solution
                        if(solveGrid()) {
                            cout << "Value " << (x + 1) << " in cell " << row << "," << column << " WORKS\n";
                            displayBoard();
                            cout << "FINAL SOLUTION\n";
                            return 1;
                        }
                        else {
                            if(zerError) {
                                zerError = false;
                                cout << "Value " << (x + 1) << " in cell " << row << "," << column << " failed\n";
                                //memcpy(grid, savedGrid, sizeof(savedGrid));
                            }
                            else {
                                cout << "Value " << (x + 1) << " in cell " << row << "," << column << " maybe\n";
                            }
                            
                        }

                        displayBoard();
                    }

                    
                }

            }
        }
    }
}




bool Sudoku::solveGrid() {
    int totalSolutions = 0;
    int newSolutions = 0;

    int passNumber = 0;

    while((totalSolutions != (GRID_SIZE * GRID_SIZE)) && (newSolutions != 0 || passNumber < 5)) {
        newSolutions = 0;
        totalSolutions = 0;

        for(int r=0; r<GRID_SIZE; r++) {

            //iterate through columns
            for(int c=0; c<GRID_SIZE; c++) {

                //test to see if solved (previously solved or newly solved)
                if(isSolved(r, c)) {
                    if(zerError) {
                        //zeroError = false;
                        return false;
                    }
                    totalSolutions++;
                    newSolutions = (sudokuGrid[r][c].solved) ? newSolutions : newSolutions + 1;

                    handleSolution(r, c);
                }
            }
        }

        passNumber++;

        //displayBoard();
        cout << "There were " << newSolutions << " new solutions that pass\n";


        
    }

    //true if there is a full grid of solutions

    cout << "Total Solved Values " << totalSolutions << "\n";
    return (bool) (totalSolutions == (GRID_SIZE * GRID_SIZE));

}



void Sudoku::fileToGrid(const char * fileName) {
    char buf;

    ifstream file;
    file.open(fileName);


    for(int i=0; i<GRID_SIZE; i++) {

        for(int j=0; j<GRID_SIZE; j++) {
            
            file >> buf;

            //if unsolved value
            if(buf == 'X') {
                sudokuGrid[i][j].solved = false;
            }

            //if solved value
            else {
                sudokuGrid[i][j].solvedVal = atoi(&buf);  //convert from char to int value
                sudokuGrid[i][j].solved = true;
            }
        }
    }
}


//only for 9 x 9 grid
void Sudoku::displayBoard() {
    char val[1];

    //itterate row
    for(int i=0; i<GRID_SIZE; i++) {

        //draw horizontal line
        if((i % SGRID_SIZE) == 0) {
            for(int x=0; x<(GRID_SIZE * 2) + (GRID_SIZE * 2 / SGRID_SIZE) + 1; x++) {
                cout << "-";
            }
            cout << "\n";
        }

        //itterate collumn
        for(int j=0; j<GRID_SIZE; j++) {
            
            //draw vertical lines
            if((j % SGRID_SIZE) == 0) {
                cout << "| ";
            }

            //write specific value
            if(sudokuGrid[i][j].solved == true) {
                /*val[0] = ' ';
                itoa(grid[i][j].solvedVal, val, 10);
                cout << val[0] << " ";*/
                cout << sudokuGrid[i][j].solvedVal << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << "|\n";
    }

    //horizontal line finishes grid
    for(int x=0; x<(GRID_SIZE * 2) + (GRID_SIZE * 2 / SGRID_SIZE) + 1; x++) {
        cout << "-";
    }
    cout << "\n";
}


void Sudoku::deleteFromRow(int row, int num) {

    //iterates through each cell in row
    for(int i=0; i<GRID_SIZE; i++) {

        //checks to see if not already solved
        if(!sudokuGrid[row][i].solved) {

            sudokuGrid[row][i].vals[num - 1] = 0;
        }
    }
}

void Sudoku::deleteFromColumn(int column, int num) {

    //iterates through each cell in column
    for(int i=0; i<GRID_SIZE; i++) {
        
        //checks to see if not already solved
        if(!sudokuGrid[i][column].solved) {

            sudokuGrid[i][column].vals[num - 1] = 0;
        }
    }
}

void Sudoku::deleteFromSubcell(int row, int column, int num) {
    int subCellRow = (int) row / SGRID_SIZE;
    int subCellColumn = (int) column / SGRID_SIZE;


    for(int ir=0; ir<SGRID_SIZE; ir++) {

        for(int ic=0; ic<SGRID_SIZE; ic++) {

            sudokuGrid[(subCellRow * SGRID_SIZE) + ir][(subCellColumn * SGRID_SIZE) + ic].vals[num - 1] = 0;
        }
    }

}

bool Sudoku::isSolved(int row, int column) {
    int total = 0;

    //if already existing solution
    if(sudokuGrid[row][column].solved) {
        return true;
    }

    //if total is one then theres only one solution
    for(int i=0; i<GRID_SIZE; i++) {
        total = (sudokuGrid[row][column].vals[i] == 1) ? total + 1: total;
    }

    //cout << "Possible Solutions for " << row << "," << column << ": " << total << endl;
    sudokuGrid[row][column].numSolutions = total;

    if(total > 1) {
        return false;
    }
    else if(total == 1) {
        return true;
    }
    else {
        cout << "ERROR 0 possible values\n";
        zerError = true;
        return false;
    }

}

void Sudoku::handleSolution(int row, int column) {

    //if there is a new solution but the cell has not been set to true
    if(!sudokuGrid[row][column].solved) {
        sudokuGrid[row][column].solved = true;

        //cout << "New Solution!\n";

        for(int i=0; i<GRID_SIZE; i++) {

            //finds the last remaining possible solution
            if(sudokuGrid[row][column].vals[i] == 1) {
                sudokuGrid[row][column].solvedVal = i + 1;
            }
        }
    }

    deleteFromColumn(column, sudokuGrid[row][column].solvedVal);

    deleteFromRow(row, sudokuGrid[row][column].solvedVal);

    deleteFromSubcell(row, column, sudokuGrid[row][column].solvedVal);
}

int Sudoku::getCell(int row, int column) {
    return sudokuGrid[row][column].solvedVal;
}

void Sudoku::setCell(int row, int column, int num) {
    sudokuGrid[row][column].solved = true;
    sudokuGrid[row][column].solvedVal = num;
}