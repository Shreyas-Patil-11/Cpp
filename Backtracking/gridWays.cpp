#include<iostream>
#include<string>
#include<vector>

using namespace std;

int gridWays(int row, int col, int n, int m){
    //Base Case
    if (row==n-1 && col==m-1)
    {
        return 1;
    }
    if (row >= n || col >=m)
    {
        return 0;
    }
    
    
    //right
    int val1 = gridWays(row, col+1, n, m);

    //down
    int val2 = gridWays(row+1, col, n, m);
    return val1+val2;
}

int main(){
    int n = 3;
    int m = 3;

    cout <<gridWays(0,0,n,m);
    return 0;
}