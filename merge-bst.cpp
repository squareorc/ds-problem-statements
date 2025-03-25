#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of a BST node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal to store elements of BST in sorted order
void inorderTraversal(TreeNode* root, vector<int>& nodes) {
    if (!root) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
}

// Merge two sorted arrays
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    return merged;
}

// Build a balanced BST from a sorted array
TreeNode* buildBalancedBST(const vector<int>& sortedArray, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(sortedArray[mid]);
    root->left = buildBalancedBST(sortedArray, start, mid - 1);
    root->right = buildBalancedBST(sortedArray, mid + 1, end);
    return root;
}

// Merge two BSTs into a single balanced BST
TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    vector<int> bst1Nodes, bst2Nodes;
    inorderTraversal(root1, bst1Nodes);
    inorderTraversal(root2, bst2Nodes);
    vector<int> mergedNodes = mergeSortedArrays(bst1Nodes, bst2Nodes);
    return buildBalancedBST(mergedNodes, 0, mergedNodes.size() - 1);
}

// Helper function to print inorder traversal of a BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Example usage
int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(7);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(8);

    TreeNode* mergedRoot = mergeBSTs(root1, root2);

    cout << "Inorder traversal of merged balanced BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}