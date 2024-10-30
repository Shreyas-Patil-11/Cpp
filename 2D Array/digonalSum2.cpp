#include<iostream>
using namespace std;

void diagonalSum2(int mat[][4],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];       //primary diag
        if (i != n-i-1)     
        {
            sum += mat[i][n-i-1];   //sec diag
        }
    }
    cout<< "Sum =" << sum <<endl;
}


int main(){
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    
    diagonalSum2(matrix, 4);
    return 0;
}