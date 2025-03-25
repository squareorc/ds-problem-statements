// find the kth, smallest, and largest element in the bst using order travel
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    inorder(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    inorder(root->right, k, result);
}

int findKthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

void reverseInorder(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    reverseInorder(root->right, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    reverseInorder(root->left, k, result);
}

int findKthLargest(TreeNode* root, int k) {
    int result = -1;
    reverseInorder(root, k, result);
    return result;
}

// Helper function to insert a node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Example usage
int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    int k = 3;
    cout << "The " << k << "rd smallest element is: " << findKthSmallest(root, k) << endl;
    cout << "The " << k << "rd largest element is: " << findKthLargest(root, k) << endl;

    return 0;
}