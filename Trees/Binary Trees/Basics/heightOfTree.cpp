#include<iostream>
#include<vector>
#include<queue>
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

static int idx = -1;
Node* buildTree(vector<int>preOrder) {
    idx++;
    if(preOrder[idx] == -1) return NULL;
    Node* root = new Node(preOrder[idx]);

    // PreOrder Traversal
    cout << root->data << " ";
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    return 0;
}