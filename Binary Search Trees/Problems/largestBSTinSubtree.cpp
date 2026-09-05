// Largest BST Subtree
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int maxNode, int minNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
private:
    NodeValue largestBSTSubtreeHelper(Node *root)
    {
        // Empty tree
        if (!root)
        {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        // Get information from left and right subtrees
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current subtree is a BST
        if (left.maxNode < root->data &&
            root->data < right.minNode)
        {
            return NodeValue(
                max(root->data, left.maxNode),  // maximum
                min(root->data, right.minNode), // minimum
                left.maxSize + right.maxSize + 1
            );
        }

        // Current subtree is NOT a BST
        // Sentinels flipped vs. the empty-tree case so an invalid
        // subtree can never be mistaken for a compatible one by its parent.
        return NodeValue(
            INT_MAX,
            INT_MIN,
            max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(Node *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

Node *buildBT(vector<int> &preorder, int &idx)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);

    root->left = buildBT(preorder, idx);
    root->right = buildBT(preorder, idx);

    return root;
}

int main()
{
    Solution S;
    int idx = -1;
    vector<int> preorder = {10, 5, 1, -1, -1, 8, -1, -1, 15, -1, 7, -1, -1};
    Node *root = buildBT(preorder, idx);

    cout << "Inorder Traversal: ";
    printInorder(root);
    cout << endl;

    auto ans = S.largestBSTSubtree(root);

    cout << "ans: " << ans << endl;
    return 0;
}