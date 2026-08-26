#include <iostream>
#include <bits/stdc++.h>
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

    if(idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void allPaths(Node* root, string path, vector<string>& ans) {

    if(root == NULL)
        return;

    // Leaf node
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }

    if(root->left) {
        allPaths(
            root->left,
            path + "->" + to_string(root->left->val),
            ans
        );
    }

    if(root->right) {
        allPaths(
            root->right,
            path + "->" + to_string(root->right->val),
            ans
        );
    }
}

vector<string> binaryTreePaths(Node* root) {
    vector<string> ans;

    if(root == NULL)
        return ans;

    string path = to_string(root->val);

    allPaths(root, path, ans);

    return ans;
}

int main() {

    vector<int> preorder = {
        1, 2, -1, 5, -1, -1, 3, -1, -1
    };

    int idx = -1;

    Node* root = buildTree(preorder, idx);

    if(root) {
        cout << "Tree building successful!\n";

        vector<string> result = binaryTreePaths(root);

        for(auto& i : result)
            cout << i << endl;
    }
    else {
        cout << "Tree building Failed!\n";
    }

    return 0;
}