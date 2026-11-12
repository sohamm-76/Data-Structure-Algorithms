#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------\n";
}

bool isSafe(vector<vector<char>>board, int row, int col){
    
}

void nQueens(vector<vector<char>>board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            nQueens(board, row+1);
            board[row][j] = '.';
        }
        
    }
}


int main(){
    vector<vector<char>> board;
    int n = 2;

    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    printBoard(board);
    nQueens(board, 0);
    return 0;
}