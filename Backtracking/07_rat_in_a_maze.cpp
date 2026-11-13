#include<iostream>
#include<string>
#include<vector>
using namespace std;

void ratMaze(int r, int c, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited, string ans){

    //BC: destination reached
    if(r == n-1 && c == n-1){
        cout << ans << endl;
        return;
    }

    //Mark current cell as visited
    visited[r][c] = true;

    //Down
    if(r+1 < n && maze[r+1][c] == 1 && visited[r+1][c] == false){
        ratMaze(r+1, c, n, maze, visited, ans+"D");
    }

    //Left
    if(c-1 >= 0 && maze[r][c-1] == 1 && visited[r][c-1] == false){
        ratMaze(r, c-1, n, maze, visited, ans+"L");
    }

    //Right
    if(c+1 < n && maze[r][c+1] == 1 && visited[r][c+1] == false){
        ratMaze(r, c+1, n, maze, visited, ans+"R");
    }

    //Up
    if(r-1 >= 0 && maze[r-1][c] == 1 && visited[r-1][c] == false){
        ratMaze(r-1, c, n, maze, visited, ans+"U");
    }

    //Backtracking
    visited[r][c] = false;
}

int main(){

    int n = 4;


    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string ans = "";

    if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
        cout << "No path exists";
    }
    else{
        ratMaze(0, 0, n, maze, visited, ans);
    }
    return 0;
}