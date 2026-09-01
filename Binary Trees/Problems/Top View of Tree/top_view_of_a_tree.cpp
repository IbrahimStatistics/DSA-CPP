#include<bits/stdc++.h>
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
Node* buildTree(vector<int>& preOrder) {
    idx++;
    if(preOrder[idx] == -1) return NULL; 
    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// Top view of a binary tree
void topView(Node* root) {
    queue<pair<Node*, int>> q; // (node, HD)
    map<int, int> map; // <HD, node val>

    q.push({root, 0});

    while(q.size()>0) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        
        if(map.find(currHD) == map.end()) {
            map[currHD] = curr->data;
        }

        if(curr->left) {
            q.push({curr->left, currHD-1});
        }

        if(curr->right) {
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it : map) {
        cout << it.second << " ";
    }

    cout << endl;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    if(root) {
        cout << "Tree building successful!\n";
        cout << "Top View: ";
        topView(root);
    } else {
        cout << "Tree building failed\n";
    }

    return 0;
}