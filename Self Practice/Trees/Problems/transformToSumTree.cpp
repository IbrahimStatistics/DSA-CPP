#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& preorder, int& idx) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void preorderTraversal(Node* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int sumTree(Node* root) {
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->val += leftSum + rightSum;
    return root->val;
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int idx = -1;
    Node* root = buildTree(preorder, idx);

    if(root) {
        cout << "Tree building successful!\n";
        cout << "Before Transform Sum: "; preorderTraversal(root); cout << endl;
        cout << "Transformed Sum Tree: " << sumTree(root) << endl;
        cout << "After Transform Sum: "; preorderTraversal(root); cout << endl;
    } else {
        cout << "Tree building failed!\n";
    }
}