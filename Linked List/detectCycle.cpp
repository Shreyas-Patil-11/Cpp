#include<iostream>
#include<List>

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

bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow-> next;
        fast = fast -> next -> next;

        if (slow == fast)
        {
            cout << "Cycle Exists"<<endl;
            return true;
        }
    }
        cout << "Cycle dosent exist"<< endl;
        return false; 
}


void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next !=NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast)
        {
            cout << "Cycle detected"<< endl;
            isCycle = true;
            break;
        }
        
    }
    if (!isCycle)
    {
        cout << "Cycle doesnt exist" <<endl;
        return;
    }
    
    slow = head;
    if (slow == fast)  // special case: tail -> head
    {
        while (fast -> next != slow)
        {
            fast = fast-> next;
        }
        fast -> next = NULL;
        
    }else {
        Node* prev = fast;
        while (slow != fast)
        {
            slow = slow-> next;
            prev = fast;
            fast = fast -> next;
        }
        prev->next = NULL; 
    }
    
}

Node* splitAtMid(Node* head){
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow-> next;
        fast = fast->next->next; 
    }
    if (prev!= NULL)
    {
        prev->next = NULL;  //split at middle
    }

    return slow;    
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while (i != NULL && j!= NULL)
    {
        if (i -> data <= j -> data)
        {
            ans.push_back(j->data);
            i = i->next;
        }else{
            ans.push_back(i->data);
            j = j->next;
        }
        
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i-> next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j-> next;
    }
    
    
    return ans.head;
}

Node* mergeSort(Node* head){
    if (head ==NULL || head -> next == NULL)
    {
        return head;
    }
    
    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);  //left head
    Node* right = mergeSort(rightHead); // right head

    return merge(left, right);  //head of sorted ll
}

Node* reverse(Node* head ){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while (curr != NULL)
    {
        next = curr -> next;
        curr-> next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
}

Node* zigZagLL(Node* head){
    if (!head || !head->next) return head;
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    //alternate merging : 1st head = head; 2nd head = rightHeadRev
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while (left != NULL && right != NULL)
    {
        Node* nextLeft = left -> next;
        Node* nextRight = right -> next;

        left->next= right;
        right->next = nextLeft;
        tail = right;

        left = nextLeft;
        right = nextRight;
    }
    
    if (right != NULL)
    {
        tail -> next = right;
    }
    return head;
}

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printList(ll.head);
    // ll.head = mergeSort(ll.head);
    //1->2->3->4->5
    // ll.tail-> next = ll.head;

    // printList(ll);
    // isCycle(ll.head);
    // removeCycle(ll.head);
    ll.head = zigZagLL(ll.head);
    printList(ll.head);
    return 0;
}