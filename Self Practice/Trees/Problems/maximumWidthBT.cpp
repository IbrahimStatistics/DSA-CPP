#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

TreeNode* buildTree(vector<int>& preorder, int& idx) {
    idx++; // Move to next index
    
    // Check if idx is out of bounds or value is -1 (null)
    if(idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

int maxWidthBT(TreeNode* root) {
    if(root == NULL) return 0;

    int maxWidth = 0;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for(int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
            }

            if(curr->right) {
                q.push(curr->right);
            }
        }
    }

    return maxWidth;
}

int main () {
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9};
    int idx = -1;

    TreeNode* root = buildTree(preorder, idx);

    if(root) {
        cout << "Tree built successfully!\n";
        cout << "Max Width : " << maxWidthBT(root) << endl;
    } else {
        cout << "Tree building failed!\n";
    }
    
    return 0;
}