#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode* parent = NULL;
    int key = 0;
    TreeNode() = default;
};

TreeNode* search(TreeNode* root, int key) {
    TreeNode* curr = root;
    while(curr!=NULL) {
        if (curr->key == key) return curr;
        if (curr->key > key) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return NULL;
}

void multiple_search(TreeNode* node, int key) {
    if (node == NULL) return;
    
    if (node->key == key) {
        cout << node << " " << node->key << endl;
    }
    
    if (node->key >= key) {
        multiple_search(node->left, key);
    }
    
    if (node->key <= key) {
        multiple_search(node->right, key);
    }
}

TreeNode* minimum(TreeNode* node) {
    while (node != NULL && node-> left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* maximum(TreeNode* node) {
    while (node != NULL && node-> right != NULL) {
        node = node->right;
    }
    return node;
}


int height(TreeNode* node) {
    if (node == NULL) return 0;
    else return max(height(node->left) + 1, height(node->right) + 1);
}

void inorder_traversal(TreeNode* node, vector<int>&node_keys) {
  if (node == NULL) return;
  //cout<<node->key<<" ";
  if (node->left!=NULL) inorder_traversal(node->left, node_keys);
  if (node!=NULL) node_keys.push_back(node->key);
  if (node->right!=NULL) inorder_traversal(node->right, node_keys);
}

bool isBST(TreeNode* root) {
  TreeNode* curr = root;
  //return recursive_search(curr);
  vector<int>node_keys;
  inorder_traversal(root, node_keys);
  for(int i = 0; i<node_keys.size()-1; i++) {
    if (node_keys[i]<=node_keys[i+1]) continue;
    else return false;
  }
  return true;
}

TreeNode* successor(TreeNode* node) {
    if (node->right!=NULL){
        return minimum(node->right);
    }
    while(node->parent!= NULL && node->parent->right == node) {
        node = node->parent;
    }
    return node->parent;
}

TreeNode* predecessor(TreeNode* node) {
    if (node->left!=NULL){
        return maximum(node->right);
    }
    while(node->parent!= NULL && node->parent->left == node) {
        node = node->parent;
    }
    return node->parent;
}

int main() {
    TreeNode* root = new TreeNode;
    root->key = 2;
    root->left = new TreeNode;
    root->left->key = 0;
    root->right = new TreeNode;
    root->right->key = 2;
    root->right->right = new TreeNode;
    root->right->right->key = 3;
    
    // if (isBST(root)) {
    //     cout << "The tree is a Binary Search Tree." << endl;
    // } else {
    //     cout << "The tree is not a Binary Search Tree." << endl;
    // }
    
    // cout<<search(root, 2)->key<<" ";
    // multiple_search(root, 2);
    // cout<<minimum(root)<<" "<<minimum(root)->key<<endl;
    // cout<<maximum(root)<<" "<<maximum(root)->key<<endl;
}