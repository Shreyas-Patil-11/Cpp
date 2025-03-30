#include<iostream>
#include<string>
#include<vector>

using namespace std;

void solveMazeUtil(int maze[][4], int row, int col, string ans, int n,  vector<vector<bool>> vis){

}

void solveMaze(int maze[][4], int n){
    string ans = "";
    vector<vector<bool>> vis(n, vector<bool> (n, false));

    if (maze[0][0] ==1)
    {
        solveMazeUtil(maze, 0, 0, ans, n, vis);
    }
    
}

int main(){
    int n = 4;
    int maze[4][4]={(1,0,0,0),
                    (1,1,0,1),
                    (1,1,0,0),
                    (0,1,1,1)};

    solveMaze(maze, n);
    return 0;
}