#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;

void reverse(queue<int> &q){
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // while (!s.empty())
    // {
    //     cout<< s.top() << " ";
    //     s.pop();
    // }   
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q1;
    for (int i = 1; i <= 5; i++)
    {
        q1.push(i);
    }

    reverse(q1);

    for (int i = 1; i <= 5; i++)
    {
        cout<< q1.front() <<endl;
        q1.pop();
    }
    return 0;
}