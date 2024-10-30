#include<iostream>

using namespace std;

int diagonalSum(int mat[][4], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)         //rows
    {
        for (int j = 0; j < n; j++)     //cols
        {
            if (i==j)
            {
                sum += mat[i][j];
            }else if (j == n-i-1)
            {
                sum += mat[i][j];
            }
        }
    }
    cout<< "Sum =" << sum <<endl;
    return 0;
}

int main(){
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    
    diagonalSum(matrix, 4);

    return 0;
}