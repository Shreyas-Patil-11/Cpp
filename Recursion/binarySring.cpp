//without consecutive 1's

#include<iostream>
#include<string>

using namespace std;

void binaryStr(int n, int lastPlace, string ans){
    //base case
    if (n==0)
    {
        cout << ans <<endl;
        return;
    }
    
    if(lastPlace != 1){
        binaryStr(n-1, 0, ans+'0');
        binaryStr(n-1, 1, ans+'1');
    }else{
        binaryStr(n-1, 0, ans+'0');
    }
}

int main(){
    int n=3;
    int lastPlace = 0;
    string ans = "";

    binaryStr(n, lastPlace, ans);
    return 0;
}