#include<iostream>
#include<stack>
#include<vector>
#include<string>


using namespace std;

bool isDuplicate(string str){       //O(n)
    stack<int> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch  = str[i];
        if (ch != ')')
        {
            s.push(ch);
        } else{
            if (s.top() == '(')
            {
                return true;
            }
            while (s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string str1= "((a+b))"; //true
    string str2= "((a+b) + (c+d))";// false
    cout<< isDuplicate(str1)<<endl;
    cout<< isDuplicate(str2)<<endl;
    return 0;
}