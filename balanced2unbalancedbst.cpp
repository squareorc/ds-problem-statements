// convert unbalanced bst to a balanced bst

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal to store nodes in sorted order
void storeInorder(TreeNode* root, vector<TreeNode*>& nodes) {
    if (!root) return;
    storeInorder(root->left, nodes);
    nodes.push_back(root);
    storeInorder(root->right, nodes);
}

// Function to build a balanced BST from sorted nodes
TreeNode* buildBalancedBST(vector<TreeNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = nodes[mid];

    root->left = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);

    return root;
}

// Function to convert an unbalanced BST to a balanced BST
TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    storeInorder(root, nodes);
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);

    cout << "Inorder of original unbalanced BST: ";
    printInorder(root);
    cout << endl;

    root = balanceBST(root);

    cout << "Inorder of balanced BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}