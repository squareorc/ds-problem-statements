#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void bubbleSort() {
        if (!head) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void selectionSort() {
        if (!head) return;
        Node* temp = head;
        while (temp) {
            Node* minNode = temp;
            Node* r = temp->next;
            while (r) {
                if (r->data < minNode->data) {
                    minNode = r;
                }
                r = r->next;
            }
            swap(temp, minNode);
            temp = temp->next;
        }
    }

    void insertionSort() {
        if (!head || !head->next) return;
        Node* sorted = nullptr;
        Node* current = head;
        while (current) {
            Node* next = current->next;
            if (!sorted || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }
};

int main() {
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(5);
    list.insert(1);
    list.insert(3);

    cout << "Original List: ";
    list.display();

    cout << "Bubble Sort: ";
    list.bubbleSort();
    list.display();

    list.insert(4);
    list.insert(2);
    list.insert(5);
    list.insert(1);
    list.insert(3);

    cout << "Selection Sort: ";
    list.selectionSort();
    list.display();

    list.insert(4);
    list.insert(2);
    list.insert(5);
    list.insert(1);
    list.insert(3);

    cout << "Insertion Sort: ";
    list.insertionSort();
    list.display();

    return 0;
}