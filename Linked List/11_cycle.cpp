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

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "Linked List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ✅ Detect Cycle (Floyd’s Algorithm)
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Cycle exists!\n";
            return true;
        }
    }
    cout << "Cycle doesn't exist!\n";
    return false;
}

// ✅ Remove Cycle
void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool cycleFound = false;

    // detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Cycle detected. Removing...\n";
            cycleFound = true;
            break;
        }
    }

    if (!cycleFound) {
        cout << "No cycle to remove.\n";
        return;
    }

    slow = head;
    Node* prev = NULL;

    // special case: if cycle starts from head
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
        return;
    }

    // find start of cycle
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL; // remove cycle
    cout << "Cycle removed successfully!\n";
}

int main() {
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout << "Original List:\n";
    ll.printList();

    // Create a cycle manually (4 -> 1)
    ll.tail->next = ll.head;

    // Detect cycle
    isCycle(ll.head);

    // Remove cycle
    removeCycle(ll.head);

    // Check again
    isCycle(ll.head);

    cout << "\nList after removing cycle:\n";
    ll.printList();

    return 0;
}
