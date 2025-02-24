
#include <iostream>
using namespace std;

int fabnoo(int n){
    if(n ==0 || n== 1){
        return n;
    }
    
    return fabnoo(n-1)+ fabnoo(n-2);
}

int main() {
    int n;
    cin >> n;
   int z =fabnoo(n);
   cout << z<< endl;
   
    return 0;
}