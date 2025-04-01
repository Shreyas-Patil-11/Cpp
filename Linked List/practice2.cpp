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

Node* deleteNodes (Node* head , int m, int n){
    auto pre = head ;
    while (pre)
    {
        for (int i = 0; i < m && pre; i++)
        {
            pre = pre -> next;
        }
        if (!pre)
        {
            return head;
        }
        auto cur = pre;
        for (int i = 0; i < n && cur; i++)
        {
            cur = cur -> next;
        }

        pre -> next = cur ? cur -> next : nullptr;
        pre = pre -> next;
    }
    return head;
}

int main() {

    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(7);
    ll.push_back(8);
    printList(ll.head);
    printList(deleteNodes(ll.head, 2, 2));

    return 0;
}