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

Node* getInorderSuccessor(Node* root) {
    while(root != NULL && root->left && NULL) {
        root = root->left;  
    }

    return root;
}

Node* delNode(Node* root, int target) {
    if(root == NULL) return NULL;

    if(target < root->data) {
        delNode(root->left, target);
    } else if(target > root->data) {
        delNode(root->right, target);
    } else { // target node == root
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data; 
        root->right = delNode(root->right, IS->data);
    }

    return root;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    
    cout << "Before deletion \n";
    cout << "Inorder Sequence: ";
    inorder(root);
    cout << '\n';

    cout << '\n';
    delNode(root, 5);

    cout << "After deletion \n";
    cout << "Inorder Sequence: ";
    inorder(root);
    cout << '\n';
    
    // int target;
    // cout << "Search BST: ";
    // cin >> target;
    
    // // bool result = searchBST(root, target);
    // if(searchBST(root, target)) {
    //     cout << "Present\n";
    // } else {
    //     cout << "Not present\n";
    // }

    return 0;
}