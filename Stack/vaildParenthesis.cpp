#include<iostream>
#include<stack>
#include<vector>
#include<string>


using namespace std;

bool isValid(string str){  //O(n)
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{' )
        {
            s.push(ch);
        }else{
            //closing
            if (s.empty())
            {
                return false;
            }

            //match
            int top = s.top();
            if ((top == '(' && ch == ')') || 
                (top == '[' && ch == ']') || 
                (top == '{' && ch == '}'))
            {
                s.pop();
            }else{
                return false;
            }             
        } 
    }
    // if (s.empty())
    // {
    //     return true;
    // }else{
    //     return false;
    // } or
    return s.empty();
    
}

int main(){
    string str1= "([}])";// false
    string str2= "([{}])"; //true
    cout<< isValid(str2)<<endl;
    return 0;
}