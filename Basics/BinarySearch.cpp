#include<iostream>

using namespace std;

int printBinary(int *arr, int n, int k){
    int st = 0, end = n-1;
    while (st <= end)
    {
        int mid = (st + end)/2;
        if (arr[mid] == k)
        {
            return mid;
        }else if(arr[mid] < k){
            st = mid+1;
        }else{
            end = mid - 1;
        }
        
    }
    return -1;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n =  sizeof(arr)/ sizeof(int); 


    int ans = printBinary(arr, n, 5);
    cout<< ans;
}