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

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ✅ Split Linked List at Mid
Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
        prev->next = NULL; // split

    return slow; // right half head
}

// ✅ Merge Two Sorted Linked Lists
Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

// ✅ Merge Sort on Linked List
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

// ✅ Reverse Linked List
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // prev becomes new head
}

// ✅ Zigzag Linked List (alternate merge of left + reversed right)
Node* zigzagLL(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rightHead = splitAtMid(head);
    Node* right = reverse(rightHead);
    Node* left = head;
    Node* tail = NULL;

    while (left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        if (nextLeft == NULL)
            break;
        right->next = nextLeft;

        tail = right;
        left = nextLeft;
        right = nextRight;
    }

    if (right != NULL)
        tail->next = right;

    return head;
}

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(9);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(2);

    cout << "Original List:\n";
    ll.printList();

    ll.head = mergeSort(ll.head);
    cout << "\nSorted List (using Merge Sort):\n";
    ll.printList();

    ll.head = zigzagLL(ll.head);
    cout << "\nZigzag List:\n";
    ll.printList();

    return 0;
}
