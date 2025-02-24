// We are given a string S,we need to find the count of all contiguous substring s starting and ending with thesame character.[Leetcode Premium Qs]
// Sample Input 1:S="abcab" 
// Sample Output 1: 7

#include<iostream>
#include<string>

using namespace std;

int countSubstrs(string strs, int i, int j, int n){
    if (n <= 0)
    {
        return 0;
    }

    int count = countSubstrs(strs, i+1, j, n-1)+
                countSubstrs(strs, i, j-1, n-1)-
                countSubstrs(strs, i+1, j-1, n-2);
    
    if (strs[i] == strs[j]) 
    {
        count++;
    }
    
    return count;
}


int main(){
    string str = "abcab";
    int n = str.size();

    cout<< countSubstrs(str, 0, n-1, n)<<endl;

    return 0;
}