#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        
    }
};

class List {
    
    public:
    Node* head;
    Node* tail;

        List(){
            head = NULL;
            tail =NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);

            if (tail == NULL)  
            {
                head = tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            
        }

        void pop_front(){
            if (head == NULL)
            {
                return;
            }
            
            Node* temp = head;
            head = head->next;
            temp = NULL;
            delete temp;
        }

        void pop_back(){
            Node* temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void push_back(int val){
            Node* newNode = new Node(val);

            if (head == NULL)  
            {
                head = tail = newNode;
            }else{
                tail -> next = newNode;
                tail  = newNode;
            } 
        }
};

void printList (Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << "->";
        temp = temp->next;
    }    
    cout <<"NULL\n"; 
}

int getSize(Node* head){
    int sz = 0;
    while (head != NULL)
    {
        head= head->next;
        sz++;
    }
    return sz;
}

Node* getIntersectionNode(Node* headA, Node* headB){
    int m = getSize(headA);
    int n = getSize(headB);

    Node* t1 =headA;
    Node* t2 = headB;

    int diff = 0;

    if (m >= n)
    {
        diff = m-n;
        for (int i = 0; i < diff; i++)
        {
            t1 = t1-> next;
        }
    }else{
        diff = n-m;
        for (int i = 0; i < diff; i++)
        {
            t2 = t2-> next;
        }
    }
    
    while (t1 != NULL && t2!= NULL && t1 != t2)
    {
        t1 = t1-> next;
        t2 = t2-> next;
    }
    if (t1 == NULL)
    {
        return NULL;
    }else{
        return t1;
    }
    
}

int main() {
    List l1;
 
    l1.push_front(5);
    l1.push_front(4);
    

    List l2;
    l2.push_front(7);
    l2.push_front(6);
    l2.push_front(3);
    l2.push_front(2);
    l2.push_front(1);

    l1.tail -> next = l2.head -> next -> next -> next;
    
    printList(getIntersectionNode(l1.head, l2.head));
    return 0;
}