#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

Node* insert(Node* root, int val) {
    if(root == NULL)
        return new Node(val);
    
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int>& arr) {
    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

bool searchBST(Node* root, int target) {
    if(root == NULL) return false;
    if(root->data == target) return true;

    if(root->data < target)
        return searchBST(root->right, target); 

    if(root->data > target)
        return searchBST(root->left, target); 
}

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    
    // cout << "Inorder Sequence: ";
    // inorder(root);
    // cout << '\n';
    
    int target;
    cout << "Search BST: ";
    cin >> target;
    
    // bool result = searchBST(root, target);
    if(searchBST(root, target)) {
        cout << "Present\n";
    } else {
        cout << "Not present\n";
    }

    return 0;
}