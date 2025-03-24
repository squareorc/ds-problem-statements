#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert_at_end(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void delete_node(int key) {
        Node* temp = head;
        if (temp && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Key not found" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insert_at_end(10);
    sll.insert_at_end(20);
    sll.insert_at_beginning(5);
    sll.display();
    sll.delete_node(20);
    sll.display();
    return 0;
}