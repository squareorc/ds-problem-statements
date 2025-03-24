#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Custom Queue Implementation
struct QueueNode {
    TreeNode* treeNode;
    QueueNode* next;

    QueueNode(TreeNode* node) : treeNode(node), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(TreeNode* node) {
        QueueNode* newNode = new QueueNode(node);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    TreeNode* dequeue() {
        if (isEmpty()) return nullptr;

        QueueNode* temp = front;
        TreeNode* treeNode = temp->treeNode;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return treeNode;
    }
};

// Function to insert a node in the tree
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to perform Inorder Traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform Postorder Traversal
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function to perform Level Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        TreeNode* current = q.dequeue();
        cout << current->data << " ";

        if (current->left) q.enqueue(current->left);
        if (current->right) q.enqueue(current->right);
    }
}

// Main function
int main() {
    TreeNode* root = nullptr;

    // Insert nodes into the tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Perform tree traversals
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}