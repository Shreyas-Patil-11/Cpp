#include<iostream>
#include<vector>
// #include<list>

using namespace std;

template<class T>
class Node{
    

    public:
    T data;
    Node* next;
        Node(T val){
            data = val;
            next = NULL;
        } 
};

template<class T>
class Stack{
    // list<T> ll;
    Node<T>* head;

    public:
    //With Stl
        // void push(T val){
        //     ll.push_front(val);
        // }

        // void pop(){
        //     ll.pop_front();

        // }

        // T top(){
        //     return ll.front();
        // }

        // bool isEmpty(){      //O(1)
        //     return ll.size() == 0;
        // }

        //without stl

        Stack(){
            head = NULL;
        }

        void push(T val){
            Node<T>* newNode = new Node<T>(val);
            if (head == NULL)
            {
                head = newNode;
            }else{
                newNode -> next = head;
                head = newNode;
            }  
        }

        void pop(){
            Node<T>* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }

        T top(){
            return head -> data;
        }

        bool isEmpty(){      //O(1)
            return head == 0;
        }
};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout<< s.top() <<" ";
        s.pop();

    }
    
    return 0;
}