#include<iostream>
#include<queue>
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

    if (nodes[idx] == -1)
        return NULL;

    Node* root = new Node(nodes[idx]);

    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(q.size()>0) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(nodes);

    if(root) {
        cout << "Tree building successful!" << endl;
        levelOrder(root);
    } else {
        cout << "Tree building failed!" << endl;
    }

    return 0;
}