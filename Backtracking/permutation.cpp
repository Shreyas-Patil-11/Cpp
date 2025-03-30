#include<iostream>
#include<string>
#include<vector>

using namespace std;

void permutation(string str , string ans){
    if(str.size() == 0){
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string nextStr = str.substr(0,i)+ str.substr(i+1, str.size());
        permutation(nextStr, ans+ch);
    }
    
}

int main(){
    string str = "abc";
    string ans = "";

    permutation(str, ans);
    return 0;
}