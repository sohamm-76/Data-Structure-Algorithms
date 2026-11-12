#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printSuduko(int suduko[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << suduko[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int suduko[9][9], int row, int col, int digit){
    //vertical
    for(int i=0; i<=8; i++){
        if(suduko[i][col] == digit){
            return false;
        }
    }

    //horizontal
    for(int j=0; j<=8; j++){
        if(suduko[row][j] == digit){
            return false;
        }
    }

    //3x3 grid
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i=startRow; i<=startRow+2; i++){
        for(int j=startCol; j<=startCol+2; j++){
            if(suduko[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool sudukoSolver(int suduko[9][9], int row, int col){
    if(row == 9){
        //suduko solve
        printSuduko(suduko);
        return true;
    }

    int nextRow = row;
    int nextCol = col+1;
    if(col + 1 == 9){
        nextRow = row + 1;
        nextCol = 0;
    }


    if(suduko[row][col] != 0){
        return sudukoSolver(suduko, nextRow, nextCol);        
    }

    for(int digit=1; digit<=9; digit++){
        if(isSafe(suduko, row, col, digit)){
            suduko[row][col] = digit;
            if(sudukoSolver(suduko, nextRow, nextCol)){
                return true;
            }
            suduko[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int suduko[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};

    sudukoSolver(suduko, 0, 0);
    return 0;
}