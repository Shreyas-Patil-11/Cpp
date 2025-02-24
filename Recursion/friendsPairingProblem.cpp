#include<iostream>
#include<string>

using namespace std;

int friendsParing(int n){
    // base case
    if(n== 1 || n==2){
        return n;
    }
    return friendsParing(n-1)+ (n-1)*friendsParing(n-2);   //single paring+ double paring
}

int main(){
    cout<<friendsParing(3)<<endl;
    return 0;
}