#include <iostream>
using namespace std;

// Static Stack Implementation
class StaticStack {
private:
    int *arr;
    int top;
    int capacity;

public:
    StaticStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~StaticStack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Static Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Static Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Static Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Dynamic Stack Implementation using Linked List
class DynamicStack {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *top;

public:
    DynamicStack() {
        top = nullptr;
    }

    ~DynamicStack() {
        while (top != nullptr) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Dynamic Stack Underflow\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Dynamic Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    // Static Stack Example
    StaticStack staticStack(5);
    staticStack.push(10);
    staticStack.push(20);
    cout << "Static Stack Top: " << staticStack.peek() << endl;
    staticStack.pop();
    cout << "Static Stack Top after pop: " << staticStack.peek() << endl;

    // Dynamic Stack Example
    DynamicStack dynamicStack;
    dynamicStack.push(30);
    dynamicStack.push(40);
    cout << "Dynamic Stack Top: " << dynamicStack.peek() << endl;
    dynamicStack.pop();
    cout << "Dynamic Stack Top after pop: " << dynamicStack.peek() << endl;

    return 0;
}