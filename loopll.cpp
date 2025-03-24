#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect and remove a loop in the linked list
void detectAndRemoveLoop(Node* head) {
    if (!head || !head->next) return;

    Node *slow = head, *fast = head;

    // Detect loop using Floyd's cycle-finding algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected, now remove it
            break;
        }
    }

    if (slow == fast) {
        slow = head;
        if (slow == fast) {
            // Special case: loop starts at the head
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = nullptr; // Remove the loop
    }
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a loop in the linked list
void createLoop(Node* head, int pos) {
    if (pos == 0) return;

    Node* temp = head;
    Node* loopNode = nullptr;
    int count = 1;

    while (temp->next) {
        if (count == pos) loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode; // Create the loop
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    createLoop(head, 3); // Create a loop at position 3

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}