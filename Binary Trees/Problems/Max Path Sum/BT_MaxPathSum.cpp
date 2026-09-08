#include<iostream>
#include<vector>
#include<algorithm>
#include<algorithm>
#include<limits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

TreeNode* buildBT(vector<int>& preorder, int& idx) {
    idx++;
    if(preorder[idx] == -1) return NULL;
    TreeNode* root = new TreeNode(preorder[idx]);

    root->left = buildBT(preorder, idx);
    root->right = buildBT(preorder, idx);

    return root;
}

void printPreorder(TreeNode* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

class Solution {
public:
    int maxPath = -1001;
    
    int helper(TreeNode* root) {
        if(root == NULL) return 0;

        int leftMax = max(0, helper(root->left));
        int rightMax = max(0, helper(root->right));

        maxPath = max(maxPath, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
       helper(root);
       return maxPath;
    }
};

int main() {
    Solution S;
    vector<int> preorder = {1, 2, -1, -1, 3, -1, -1};
    int idx = -1;
    TreeNode* root = buildBT(preorder, idx);

    cout << "Preorder: "; printPreorder(root);
    cout << endl;

    cout << "Max Path Sum: " << S.maxPathSum(root);
    cout << endl;

    return 0;
}