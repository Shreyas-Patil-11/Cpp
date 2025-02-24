// For a given integer array of size N.You have to find all the occurrences ( indices) of a given element (Key) and print them.Use a recursive function to solve this problem. Sample Input :
// arr[]={3,2,4,5,6,2,7,2,2}, key=2

#include<iostream>
#include<string>

using namespace std;

void allOccurance(int arr[], int key, int i, int n){
    if(i==n){
        return;
    }

    if(arr[i] == key){
        cout<< i;
    }

    allOccurance(arr,key,i+1,n);
}

int main(){

    int arr[]={3,2,4,5,6,2,7,2,2};
    int key = 2;
    int i=0;
    int n= 9;
    
    allOccurance(arr, key, i, n);
    return 0;
}