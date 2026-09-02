// Minimum distance between two TreeNodes

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int data)
    {
        val = data;
    }
};

// Insert a value into the BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Build BST from array
TreeNode *buildBST(vector<int> &preorder)
{
    TreeNode *root = NULL;

    for (int val : preorder)
    {
        root = insert(root, val);
    }

    return root;
}

// Print inorder traversal
void printInorderSequence(TreeNode *root)
{
    if (root == NULL)
        return;

    printInorderSequence(root->left);
    cout << root->val << " ";
    printInorderSequence(root->right);
}

// Store inorder traversal
vector<int> inorder;

void calculateInorder(TreeNode *root)
{
    if (root == NULL)
        return;

    calculateInorder(root->left);
    inorder.push_back(root->val);
    calculateInorder(root->right);
}

// Find minimum difference between two nodes
int minDiffInBST(TreeNode *root)
{
    inorder.clear();

    calculateInorder(root);

    int minDistance = INT_MAX;

    for (int i = 1; i < inorder.size(); i++)
    {
        minDistance = min(minDistance,
                          inorder[i] - inorder[i - 1]);
    }

    return minDistance;
}

int main()
{
    vector<int> preorder = {83, 62, 42, 52, 82, 88};

    TreeNode *root = buildBST(preorder);

    cout << "Inorder Sequence: ";
    printInorderSequence(root);
    cout << "\n";

    cout << "Minimum Distance: "
         << minDiffInBST(root) << "\n";

    return 0;
}