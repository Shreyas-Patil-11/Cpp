#include<iostream>
#include<algorithm>

using namespace std;

int printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<< " ";
    }
}

int main(){
    int arr[8]= {1,4,1,3,2,4,3,7};

    //for complete array
    sort(arr, arr+8);
    //Output : 1 1 2 3 3 4 4 7 

    //for specific elements
    sort(arr+2, arr+6);
    //Output: 1 4 1 2 3 4 3 7 

    //for desnding order
    sort(arr, arr+8, greater<int>());

    printArr(arr,8);
    return 0;
}