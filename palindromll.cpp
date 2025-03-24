#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;
    stack<int> s;

    // Push first half elements onto the stack
    while (fast && fast->next) {
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Skip the middle element for odd-length lists
    if (fast) {
        slow = slow->next;
    }

    // Compare the second half with the stack
    while (slow) {
        if (s.top() != slow->data) {
            return false;
        }
        s.pop();
        slow = slow->next;
    }

    return true;
}

// Helper function to add a node at the end
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    printList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}