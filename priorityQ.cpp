#include <iostream>

using namespace std;

class PriorityQueue {
private:
    struct Node {
        string data;
        int priority;
        Node* next;
    };
    
    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    void push(string item, int priority) {
        Node* newNode = new Node{item, priority, nullptr};
        
        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    string pop() {
        if (!head) return "";
        Node* temp = head;
        string item = head->data;
        head = head->next;
        delete temp;
        return item;
    }

    string peek() {
        return head ? head->data : "";
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    PriorityQueue pq;
    pq.push("Task A", 2);
    pq.push("Task B", 1);
    pq.push("Task C", 3);

    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;

    return 0;
}
