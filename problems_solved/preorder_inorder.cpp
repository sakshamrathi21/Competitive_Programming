#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int* preorderwalk, int* inorderwalk, int start, int end) {
    static int preIndex = 0; // Added to keep track of the index in preorder array
    if (start > end) return nullptr;

    int rootvalue = preorderwalk[preIndex++];
    TreeNode* root = new TreeNode(rootvalue);

    int i;
    for (i = start; i <= end; i++) {
        if (inorderwalk[i] == rootvalue) break;
    }

    root->left = buildTree(preorderwalk, inorderwalk, start, i - 1);
    root->right = buildTree(preorderwalk, inorderwalk, i + 1, end);

    return root;
}

void printTreeInOrder(TreeNode* root) {
    if (root == nullptr) return;

    printTreeInOrder(root->left);
    cout << root->val << " ";
    printTreeInOrder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder, 0, 4); // Changed end index to 4
    printTreeInOrder(root);
}
