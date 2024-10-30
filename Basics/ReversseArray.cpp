#include <iostream>

using namespace std;

//With Extra Space

// int printFunction(int *arr,int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << ",";
//     }
    
// }

// int main (){
//     int arr[] = {1,2,3,4,5};
//     int n =  sizeof(arr)/ sizeof(int);
//     int copyArr [n];

//     for (int i = 0; i < n; i++)
//     {
//         int j = n-i-1;
//         copyArr[i] = arr[j];
        
//     }

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = copyArr[i];
//     }
    
//     printFunction(arr, n);

//     return 0;
// }


//Without extra spaces

int printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<< ",";
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n =  sizeof(arr)/ sizeof(int); 
    int start= 0,end =n-1;

    while (start < end) 
    {
        //Type 1 of swapping
        // int temp = arr[start];
        // arr[start]= arr[end];
        // arr[end] = temp;

        //Type 2 of swapping
        swap(arr[start], arr[end]);

        start++;
        end--;
    }
    
    printArr(arr, n);
    return 0;
}