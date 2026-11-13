#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Check if the move is Safe
bool isSafe(int r, int c, int n, vector<vector<int>>& board){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }

    if(board[r][c] != -1){
        return false;
    }

    return true;
}

//Count possible next moves
int countMoves(int r, int c, int n, vector<vector<int>>& board, int dx[],int dy[]){
    int count = 0;

    for(int i=0; i<8; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];

        if(isSafe(nr, nc, n, board)){
            count++;
        }
    }
    return count;
}

//Knight's Tour
bool knightTour(int r, int c, int moveNo, int n, vector<vector<int>>& board, int dx[], int dy[]){

    //BC: All cells visited
    if(moveNo == n*n){
        return true;
    }

    //Store possible next moves
    vector<pair<int, pair<int, int>>>moves;

    for(int i=0; i<8; i++){

        int nr = r + dx[i];
        int nc = c + dy[i];

        if(isSafe(nr, nc, n, board)){
            int degree = countMoves(nr, nc, n, board, dx, dy);

            moves.push_back({degree, {nr, nc}});
        }
    }



    //Try moves having fever onward choices first
    sort(moves.begin(), moves.end());

    //Explore all possible ways
    for(auto move: moves){

        int nr = move.second.first;
        int nc = move.second.second;

        //Mark the cell
        board[nr][nc] = moveNo;

        //Recursive call
        if(knightTour(nr, nc, moveNo+1, n, board, dx, dy)){
            return true;
        }

        //Backtracking 
        board[nr][nc] = -1;
    }

    return false;
}

int main(){
    int n = 8;

    vector<vector<int>> board(n, vector<int>(n, -1));

    //8 possible knight moves
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    //Starting position
    board[0][0] = 0;

    if(knightTour(0, 0, 1, n, board, dx, dy)){

        cout << "Knight's Tour Solution: " << endl;

        for(int i=0; i<n; i++){

            for(int j = 0; j<n; j++){
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists";
    }
    return 0;
}