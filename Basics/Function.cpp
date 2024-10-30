#include <iostream>
using namespace std;

// bool isPrime(int n){
//     if (n == 1)
//     {
//         return false;
//     }

//     for (int i = 2; i <= n-1; i++)
//     {
//         if (n%i == 0)
//         {
//             return false;
//         }
        
//         return true;
//     }
    
// }

// void checkPrime(int n ){
//     for (int i = 2; i <= n; i++)
//     {
//        if (isPrime(i))
//        {
//             cout<< i << " ";
//        }
        
//     }
    
// }

//Write a function to check if a number is a palindrome in C++.(121 is a palindrome,321 is not)

// int reverse (int n){
//     int res = 0;
//     while (n > 0)       
//     {
//         int lastDigit = n % 10;
//         res = res * 10 + lastDigit;
//         n= n/10;
//     }
//     return res;
    
// }

// int isPalindrome(int n){
//     int revNum = reverse(n);
//     return n == revNum;
// }

// Write a function to calculate the sum of digits of a number.

// int calcDigit(int n){
//     int res = 0;
//     while (n > 0)
//     {
//         res += n%10;
//         n= n/10;
//     }
//     return res;
// }

// Write a function which takes 2 numbers as parameters (a & b) and outputs :a^2 +b^2 +2*ab.
// int abSquare(int a, int b){
//     return a*a+ b*b +2*a*b;
// }

// Write a function that accepts a character(ch) as parameters & returns the character that occurs after ch in the English alphabet. Eg: input = ‘c’,return value= ‘d’ Note:for ch=‘z’,return‘a’
char getNextChar(char ch){
    if (ch == 'z')
    {
        return 'a';
    }else{
        return ch+1 ;
    }
    
}

int main(){
    // checkPrime(100);
    // cout<< isPalindrome(1232);
    // cout<< calcDigit(12345);
    // cout<< abSquare(5,2);
    cout<< getNextChar('d');

    if (1+1+1+1+1 ==5)
    {
        cout<< "Treu";
    }
    
}