#include<iostream>
#include<string>

using namespace std;

int binarySearch(int arr[], int key, int low, int high){
    int mid = low + (high - low)/2;

    if (low > high)
    {
        return -1;
    }

    if (arr[mid] == key){
        return mid;
    }else if (arr[mid] > key)
    {
        return binarySearch(arr, key,low,  mid -1);
    } else{
        return binarySearch(arr, key, mid+1, high);
    }
    
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int key=5;
    int n=7;
    int low =0, high = n-1;

    cout<<binarySearch(arr, key,low, high)<<endl;
}