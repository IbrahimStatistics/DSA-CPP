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

int sumTree(Node* root) {
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    return leftSum + rightSum + root->val;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx = -1;
    Node* root = buildTree(preorder, idx);

    if(root) {
        cout << "Tree building successful!\n";
        cout << "Sum Tree: " << sumTree(root) << endl;
    } else {
        cout << "Tree building failed!\n";
    }

    return 0;
}