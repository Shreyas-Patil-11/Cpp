#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
    public:
    Node *head;
    Node *tail;


    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
    }

    void pop_back()
    {
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int search(int val)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << idx << endl;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        head = tail;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int sizeL()
    {
        Node *temp = head;
        int sz = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            sz++;
        }
    }

    int removeN(int pos)
    {
        Node *temp = head;

        for (int i = 0; i < sizeL() - pos; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle exist" << endl;
            return true;
        }
        
    }
    cout << "No Cycle" << endl;
    return false;
}

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while (fast != NULL && fast-> next != NULL)
    {
        slow = slow -> next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle detected"<< endl;
            isCycle = true;
            break;
        }
    }
    if (!isCycle)
    {
        cout << "No Cycle" << endl;
    }
    
    slow = head;
    

    if (slow == fast)
    {
        while (fast-> next != slow)
        {
            fast = fast-> next;
        }
        fast -> next = NULL;
    }else{
        Node* prev= fast;
        while (slow != fast)
        {
            slow = slow -> next;
            prev = fast;
            fast = fast->next;
        }
    }
}

Node* splitAtMid(Node* head){
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        prev= slow;
        slow = slow->next;
        fast = fast -> next-> next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }

    return slow;
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while (i != NULL && j != NULL)
    {
        if (i -> data <= j->data)
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
        ans.push_back(i-> data);
        i= i-> next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j= j->next;
    }
    
    return ans.head;
}

Node* mergeSort(Node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* righthead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(righthead);
    return merge(left, right);

}


int main()
{
    List ll;
    ll.push_front(51);
    ll.push_front(42);
    ll.push_front(33);
    ll.push_front(24);
    ll.push_front(15);
    // ll.tail->next = ll.head;

    ll.print();
    // ll.search(2);

    // ll.pop_front();
    // ll.print();
    // ll.pop_back();

    // ll.insert(2,2);

    // ll.push_back(6);
    // ll.reverse();
    // ll.removeN(2);
    // isCycle(ll.head);

    // removeCycle(ll.head);
    mergeSort(ll.head);
    

    ll.print();

    return 0;
}