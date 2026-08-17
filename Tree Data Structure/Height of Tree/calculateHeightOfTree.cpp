#include<iostream>
#include<vector>
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
Node* buildTree(vector<int>& nodes) {
    idx++;
    if(nodes[idx] == -1) return NULL;
    Node* root = new Node(nodes[idx]);
    
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

void preOrderTraversal(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight)+1;
}

int main() {
    vector<int> nodes = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(nodes);
    
    if(root) {
        cout << "Tree building successful!" << endl;
        
        cout << "In Order Traversal: ";
        preOrderTraversal(root); cout << endl;
        
        cout << "Height of Tree: ";
        cout << height(root) << endl;

    } else {
        cout << "Tree building failed!" << endl;
    }

    return 0;
}