#include<iostream>

using namespace std;

int linearSearch (int *arr, int n , int k){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int arr[] = {1,4,2,6,7,5,8,10,15};
    int n = sizeof(arr)/ sizeof(int);
    
    int ans = linearSearch(arr, n , 10);
    cout << ans << endl;

}