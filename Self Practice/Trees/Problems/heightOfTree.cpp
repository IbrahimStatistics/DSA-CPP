#include <iostream>
#include <vector>
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
        left = right = NULL;
    }
};

Node *buildTree(vector<int>& preorder, int &idx)
{
    idx++;

    if (preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);

    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return leftNodes + rightNodes + 1;
}

int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;

    else
    {
        int leftNodes = sumNodes(root->left);
        int rightNodes = sumNodes(root->right);

        return leftNodes + rightNodes + root->data;
    }
}

bool isSame(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;

    bool isLeftSame = isSame(root1->left, root2->left);
    bool isRightSame = isSame(root1->right, root2->right);

    return isLeftSame && isRightSame;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> preorder2 = {1, 10, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int idx = -1;
    Node *root1 = buildTree(preorder, idx);
    idx = -1;
    Node *root2 = buildTree(preorder2, idx);

    // if (root) {
    //     cout << "Tree building successful!\n";
    //     cout << "Height of Tree: " << height(root) << endl;
    //     cout << "Count of Nodes of Tree: " << countNodes(root) << endl;
    //     cout << "Sum of Nodes of Tree: " << sumNodes(root) << endl;
    // } else {
    //     cout << "Tree building failed!\n";
    // }

    if (root1 && root2)
    {
        cout << "Tree building successful!\n";

        if (isSame(root1, root2))
        {
            cout << "Same Trees!\n";
        }
        else
        {
            cout << "Trees are different!\n";
        }
    }
    else
    {
        cout << "Tree building failed!\n";
    }

    return 0;
}
