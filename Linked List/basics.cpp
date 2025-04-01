# include <iostream>

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
    Node* head;
    Node* tail;

    public:
        List() {
            head = NULL;
            tail = NULL;
        }

        ~List(){
            if (head != NULL)
            {
                delete head;
                head = NULL;
            }
        }

        void push_front(int val){
            Node* newNode = new Node(val);

            if (head == NULL)  
            {
                head = tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            
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

        void pop_front(){
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

        void printList(){
            Node* temp = head;
            while (temp != NULL)
            {
                cout << temp-> data << "->"; //prints data
                // cout << temp <<endl; //prints address
                temp = temp -> next;
            }
            cout<< endl;
        }

        void insert (int val , int pos ){
            Node* newNode = new Node(val);
            Node* temp = head;

            for (int i = 0; i < pos-1; i++)
            {
                temp = temp -> next;
            }

            newNode -> next = temp -> next;
            temp -> next = newNode;
            
        }

        // iteretive search
        int search(int val){
            Node* temp =head;
            int idx = 0;
            while (temp !=NULL)
            {
                if (temp->data == val)
                {
                    cout<< idx<<endl;
                }
                temp = temp -> next;  
                idx++;         
            }
            return -1;
        }

        // recurrsive search
        int recurSearch(int val){
            Node* temp = head;
            cout<< helper(temp, val);
        }

        int helper(Node* temp, int val){
            if (temp == NULL)
            {
                return -1;
            }
            
            if (temp->data == val)
            {
                return 0;
            }

            int idx = helper(temp->next, val);
            if (idx==-1)
            {
                return -1;
            }
            
            return idx+1;
        }

        int reverse(){
            Node* prev = NULL;
            Node* curr = head;
            tail = head;

            while (curr != NULL)
            {
                Node* next = curr->next;
                curr->next = prev;

                // Updations for next itr
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        int size(){
            int sz= 0;
            Node* temp = head;

            while (temp != NULL)
            {
                temp = temp->next;
                sz++;
            }
            return sz;
        }

        void removeN(int pos){
            Node* temp = head;
            for (int i = 0; i < (size()-pos); i++)
            {
                temp = temp->next;
            }
            temp ->next = temp->next->next;
        }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printList();

    // ll.insert(5,2);
    // ll.printList();

    // ll.pop_back();
    // ll.printList();
    // ll.search(2);
    // ll.recurSearch(2);
    // ll.reverse();
    // ll.printList();
    ll.removeN(3);
    ll.printList();
    return 0;

}