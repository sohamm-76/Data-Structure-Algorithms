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
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic
        // Node *newNode(val);//static
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

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
    //1->2->3 pos=25
    void insert(int val,int pos){
        Node* newNode= new Node(val);

        Node* temp = head;
        for(int i=0;i<pos-1; i++){
            if(temp == NULL){
                cout << "position is INVALID\n";
                return;
            }
            temp = temp->next;
        }

        //temp is now at pos-1 i.e prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void pop_front(){
        if(head == NULL){
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL; //temp = tail's prev
        delete tail;
        tail = temp;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    ll.insert(100,2);
    ll.printList();

    ll.pop_back();
    ll.printList();
    
    return 0;
}
