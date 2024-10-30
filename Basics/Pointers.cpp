#include <iostream>
using namespace std;

// void multiplyby2(int &a,int &b,int &c){
//     a *= 2;
//     b *= 2;
//     c *= 2;
// }

int main(){
    // int a;
    // int *ptr;
    // a=7;
    // ptr = &a;
    // cout<< *ptr ;

    // int a=1, b=2, c=3;
    // multiplyby2(a,b,c);
    // cout<< a<< b<< c;

    int a =32;
    int *ptr = &a;

    char ch ='A';
    char &cho =  ch;

    cho += a;
    *ptr += ch;

    cout << a<< "," << ch;
}