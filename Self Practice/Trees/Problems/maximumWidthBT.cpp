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
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while(q.size()>0) {
        int currLevelSize = q.size();
        int stIdx = q.front().second;
        int endIdx = q.back().second;

        maxWidth = max(maxWidth, endIdx-stIdx+1);

        for(int i = 0; i<currLevelSize; i++) {
            auto curr = q.front();
            q.pop();

            if(curr.first->left) {
                q.push({curr.first->left, curr.second*2+1});  // Left child
            }

            if(curr.first->right) {
                q.push({curr.first->right, curr.second*2+2}); // Right child (CHANGED)
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