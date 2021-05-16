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

//sudoku grid 2d array       row, column
cell grid[GRID_SIZE][GRID_SIZE];

bool zeroError = false;


void fileToGrid(const char * fileName);
void displayBoard(void);


bool isSolved(int row, int column);
void handleSolution(int row, int column);

bool solveGrid(void);

void deleteFromRow(int row, int num);
void deleteFromColumn(int column, int num);
void deleteFromSubcell(int row, int column, int num);

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fileToGrid("SUDOKU.txt");
    }
    else {
        fileToGrid(argv[1]);
    }


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

    memcpy(savedGrid, grid, sizeof(grid));      //save the last status of the solved grid


    //perform combination solve
    for(int row=0; row<GRID_SIZE; row++) {

        for(int column=0; column<GRID_SIZE; column++) {

            //finds the not solved cells
            if(!grid[row][column].solved) {

                for(int x=0; x<GRID_SIZE; x++) {
                    
                    //if its a possible value
                    if(savedGrid[row][column].vals[x] == 1) {

                        //reset grid to last know good point
                        memcpy(grid, savedGrid, sizeof(savedGrid));

                        grid[row][column].solvedVal = (x + 1);
                        grid[row][column].solved = true;

                        //test solution
                        if(solveGrid()) {
                            cout << "Value " << (x + 1) << " in cell " << row << "," << column << " WORKS\n";
                            displayBoard();
                            cout << "FINAL SOLUTION\n";
                            return 1;
                        }
                        else {
                            if(zeroError) {
                                zeroError = false;
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




bool solveGrid() {
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
                    if(zeroError) {
                        //zeroError = false;
                        return false;
                    }
                    totalSolutions++;
                    newSolutions = (grid[r][c].solved) ? newSolutions : newSolutions + 1;

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



void fileToGrid(const char * fileName) {
    char buf;

    ifstream file;
    file.open(fileName);


    for(int i=0; i<GRID_SIZE; i++) {

        for(int j=0; j<GRID_SIZE; j++) {
            
            file >> buf;

            //if unsolved value
            if(buf == 'X') {
                grid[i][j].solved = false;
            }

            //if solved value
            else {
                grid[i][j].solvedVal = atoi(&buf);  //convert from char to int value
                grid[i][j].solved = true;
            }
        }
    }
}


//only for 9 x 9 grid
void displayBoard() {
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
            if(grid[i][j].solved == true) {
                /*val[0] = ' ';
                itoa(grid[i][j].solvedVal, val, 10);
                cout << val[0] << " ";*/
                cout << grid[i][j].solvedVal << " ";
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


void deleteFromRow(int row, int num) {

    //iterates through each cell in row
    for(int i=0; i<GRID_SIZE; i++) {

        //checks to see if not already solved
        if(!grid[row][i].solved) {

            grid[row][i].vals[num - 1] = 0;
        }
    }
}

void deleteFromColumn(int column, int num) {

    //iterates through each cell in column
    for(int i=0; i<GRID_SIZE; i++) {
        
        //checks to see if not already solved
        if(!grid[i][column].solved) {

            grid[i][column].vals[num - 1] = 0;
        }
    }
}

void deleteFromSubcell(int row, int column, int num) {
    int subCellRow = (int) row / SGRID_SIZE;
    int subCellColumn = (int) column / SGRID_SIZE;


    for(int ir=0; ir<SGRID_SIZE; ir++) {

        for(int ic=0; ic<SGRID_SIZE; ic++) {

            grid[(subCellRow * SGRID_SIZE) + ir][(subCellColumn * SGRID_SIZE) + ic].vals[num - 1] = 0;
        }
    }

}

bool isSolved(int row, int column) {
    int total = 0;

    //if already existing solution
    if(grid[row][column].solved) {
        return true;
    }

    //if total is one then theres only one solution
    for(int i=0; i<GRID_SIZE; i++) {
        total = (grid[row][column].vals[i] == 1) ? total + 1: total;
    }

    //cout << "Possible Solutions for " << row << "," << column << ": " << total << endl;
    grid[row][column].numSolutions = total;

    if(total > 1) {
        return false;
    }
    else if(total == 1) {
        return true;
    }
    else {
        cout << "ERROR 0 possible values\n";
        zeroError = true;
        return false;
    }

}

void handleSolution(int row, int column) {

    //if there is a new solution but the cell has not been set to true
    if(!grid[row][column].solved) {
        grid[row][column].solved = true;

        //cout << "New Solution!\n";

        for(int i=0; i<GRID_SIZE; i++) {

            //finds the last remaining possible solution
            if(grid[row][column].vals[i] == 1) {
                grid[row][column].solvedVal = i + 1;
            }
        }
    }

    deleteFromColumn(column, grid[row][column].solvedVal);

    deleteFromRow(row, grid[row][column].solvedVal);

    deleteFromSubcell(row, column, grid[row][column].solvedVal);
}