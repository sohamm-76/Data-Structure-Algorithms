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
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
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

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Function to reverse a linked list and return new head
    Node* reverseList(Node* curr) {
        Node* prev = NULL;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true; // 0 or 1 element

        // Step 1: Find middle using slow and fast pointers
        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        slow->next = reverseList(slow->next);

        // Step 3: Compare both halves
        Node* first = head;
        Node* second = slow->next;

        while (second != NULL) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }

    Node* getHead() { return head; }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);

    cout << "Linked List: ";
    ll.printList();

    if (ll.isPalindrome())
        cout << " It is a palindrome.\n";
    else
        cout << " It is not a palindrome.\n";

    return 0;
}
