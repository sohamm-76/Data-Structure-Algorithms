#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head; // circular link
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;  // old tail points to new node
            tail = newNode;        // update tail
            tail->next = head;     // maintain circular link
        }
    }

    // ✅ Delete first node (head)
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        // Single node case
        if (head == tail) {
            cout << "Deleting node: " << head->data << endl;
            delete head;
            head = tail = NULL;
            return;
        }

        // 2 or more nodes
        Node* temp = head;
        cout << "Deleting node: " << temp->data << endl;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    void deleteAtTail(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = tail;

            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }
};

int main() {
    CircularList cll;

    // Insert at tail
    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cout << "Initial List:\n";
    cll.print();

    cout << "\nDeleting nodes one by one:\n";
    cll.deleteAtHead();
    cll.print();

    cll.deleteAtHead();
    cll.print();

    cll.deleteAtHead();
    cll.print();

    cout << "\nInserting after deletions:\n";
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.print();

    cout << "\nDeleting nodes one by one:\n";
    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    return 0;
}
