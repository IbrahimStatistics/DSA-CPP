#include <iostream>
#include <vector>
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

Node* buildTree(vector<int>& preorder, int& idx) {
    idx++;

    if (preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void preOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node* root = buildTree(preorder, idx);

    if (root) {
        cout << "Tree Building Successful!" << endl;

        cout << "PreOrder Traversal: ";
        preOrderTraversal(root); cout << endl;
        
        cout << "Inorderd Traversal: ";
        inOrderTraversal(root); cout << endl;

        cout << "Post Order Traversal: ";
        postOrderTraversal(root); cout << endl;
    } else {
        cout << "Tree Building Failed!" << endl;
    }

    return 0;
}