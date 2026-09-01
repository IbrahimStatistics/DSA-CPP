#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& preOrder) {
    idx++;

    if(preOrder[idx] == -1)
        return NULL;

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

void kthLevel(Node* root, int k) {
    // Important: stop if there is no node
    if(root == nullptr)
        return;

    // k == 1 means current node is at the requested level
    if(k == 1) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main() {
    vector<int> preOrder = {
        1, 2, 7, -1, -1, -1,
        3, 4, -1, -1,
        5, -1, -1
    };

    Node* root = buildTree(preOrder);

    if(root) {
        cout << "Tree building successful!\n";
        kthLevel(root, 3);
    } else {
        cout << "Tree building Failed\n";
    }

    return 0;
}
