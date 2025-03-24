#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Custom stack node
struct StackNode {
    Node* treeNode;
    StackNode* next;
    StackNode(Node* node) : treeNode(node), next(nullptr) {}
};

// Custom stack implementation
class Stack {
private:
    StackNode* top;
public:
    Stack() : top(nullptr) {}

    void push(Node* node) {
        StackNode* newNode = new StackNode(node);
        newNode->next = top;
        top = newNode;
    }

    Node* pop() {
        if (isEmpty()) return nullptr;
        StackNode* temp = top;
        top = top->next;
        Node* treeNode = temp->treeNode;
        delete temp;
        return treeNode;
    }

    Node* peek() {
        return isEmpty() ? nullptr : top->treeNode;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Non-recursive Preorder traversal
void preorder(Node* root) {
    if (!root) return;

    Stack stack;
    stack.push(root);

    while (!stack.isEmpty()) {
        Node* current = stack.pop();
        cout << current->data << " ";

        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
}

// Non-recursive Inorder traversal
void inorder(Node* root) {
    Stack stack;
    Node* current = root;

    while (current || !stack.isEmpty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

// Non-recursive Postorder traversal
void postorder(Node* root) {
    if (!root) return;

    Stack stack1, stack2;
    stack1.push(root);

    while (!stack1.isEmpty()) {
        Node* current = stack1.pop();
        stack2.push(current);

        if (current->left) stack1.push(current->left);
        if (current->right) stack1.push(current->right);
    }

    while (!stack2.isEmpty()) {
        cout << stack2.pop()->data << " ";
    }
}

// Function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

int main() {
    // Creating a binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
