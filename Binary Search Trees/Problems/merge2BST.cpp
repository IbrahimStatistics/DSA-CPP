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
        left = right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    if(val < root->val) {
        root->left = insert(root->left, val);
    }

    if(val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* buildBST(vector<int>& preorder) {
    TreeNode* root = NULL;

    for(int val : preorder) {
        root = insert(root, val);
    }

    return root;
}

void printInorder(TreeNode* root) {
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void getInorder(TreeNode* root, vector<int>& inorder) {
    if(root == NULL) return;

    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    int i = 0; 
    int j = 0;
    vector<int> temp;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] == arr2[j]) {
            temp.push_back(arr1[i++]);
            temp.push_back(arr2[j++]);
            continue;
        } else if(arr1[i] < arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        } else if(arr1[i] > arr2[j]) {
            temp.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        temp.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        temp.push_back(arr2[j++]);
    }

    return temp;
}

TreeNode* buildInorderBST(vector<int>& inorder, int st, int end) {
    if(st>end) {
        return NULL;
    }

    int mid = st + (end-st)/2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = buildInorderBST(inorder, st, mid-1);
    root->right = buildInorderBST(inorder, mid+1, end);

    return root;
}

int main() {
    vector<int> preorder_arr_1 = {8, 2, 1, 0};
    vector<int> preorder_arr_2 = {5, 3, 0};

    TreeNode* root1 = buildBST(preorder_arr_1);
    // cout << "Tree 1: "; printInorder(root1);
    
    // cout << endl;
    
    TreeNode* root2 = buildBST(preorder_arr_2);
    // cout << "Tree 2: "; printInorder(root2);
    
    vector<int> inorder_arr_1;
    inorder_arr_1.clear();
    getInorder(root1, inorder_arr_1);
    cout << "Inorder arr 1: ";
    for(auto i : inorder_arr_1) cout << i << " ";
    
    cout << endl;
    
    vector<int> inorder_arr_2;
    inorder_arr_2.clear();
    getInorder(root2, inorder_arr_2);
    cout << "Inorder arr 2: ";
    for(auto i : inorder_arr_2) cout << i << " ";
    
    cout << endl;

    vector<int> merged = merge(inorder_arr_1, inorder_arr_2);
    cout << "Inorder merged arr1 & arr2: ";
    for(auto i : merged) cout << i << " ";

    cout << endl;

    TreeNode* mergedRoot = buildInorderBST(merged, 0, merged.size()-1);
    cout << "Merged Tree Inorder Squence: "; printInorder(mergedRoot);
    cout << endl;
    return 0;
}