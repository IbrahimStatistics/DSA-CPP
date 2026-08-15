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
Node* buildTree(vector<int>& preorder, int idx) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx++);
    root->right = buildTree(preorder, idx++);
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1}; 

    Node* root = buildTree(preorder, idx);

    if(root) {
        cout << "Tree Built Successfully!" << endl;
    } else {
        cout << "Tree Building Failed!" << endl;
    }
    
    return 0;
}