#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Create Node class for the tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree from preorder traversal
Node* buildTree(vector<int>& preorder, int& idx) {

    idx++;

    if (preorder[idx] == -1)
        return NULL;

    Node* newNode = new Node(preorder[idx]);

    newNode->left = buildTree(preorder, idx);
    newNode->right = buildTree(preorder, idx);

    return newNode;
}

int height(Node* root) {
    if(root == NULL) return 0;

    int leftSubTreeHeight = height(root->left);
    int rightSubTreeHeight = height(root->right);

    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

// preorder   : Root Left Right
// inorder    : Left Root Right
// postorder  : Left Right Root

void preorderTraversal(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if(root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);

    levelorderTraversal(root->left);
    levelorderTraversal(root->right);

    while(q.size()) {
        cout << q.front()->data << " ";
        q.pop();
    }
}

int main() {

    vector<int> preorder = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };

    int idx = -1;

    Node* root = buildTree(preorder, idx);
    if(root) {
        cout << "Tree building successful!\n";
        cout << "Height of Tree: " << height(root) << '\n';
        cout << "Preorder Traversal: "; preorderTraversal(root); cout << '\n';
        cout << "Inorder Traversal: ";  inorderTraversal(root); cout << '\n';
        cout << "Postorder Traversal: ";  postorderTraversal(root); cout << '\n';
        cout << "Levelorder Traversal: ";  levelorderTraversal(root); cout << '\n';
    } else {
        cout << "Tree building failed!\n";
    }

    return 0;
}