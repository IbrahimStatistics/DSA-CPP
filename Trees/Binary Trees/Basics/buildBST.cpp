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
Node* buildTree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1) return NULL;
    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    
    return root;
}

void preOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// void levelOrder(Node* root) {
//     if (root == NULL) return;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();

//         for (int i = 0; i < size; i++) {
//             Node* curr = q.front();
//             q.pop();

//             cout << curr->data << " ";

//             if (curr->left != NULL) {
//                 q.push(curr->left);
//             }

//             if (curr->right != NULL) {
//                 q.push(curr->right);
//             }
//         }
//         cout << endl;
//     }
// }

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (q.size()>0) {
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;      //{1,2,-1,-1,3,4,-1,-1,5,-1,-1}
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1}; //preorder sequence  

    Node* root = buildTree(preorder);

    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    cout << "Preorder traversal: "; preOrder(root);
    cout << endl;

    cout << "Inorder traversal: "; inOrder(root);
    cout << endl;

    cout << "Postorder traversal: "; postOrder(root);
    cout << endl;

    cout << "Levelorder traversal: - " << endl; levelOrder(root);
    cout << endl;

    return 0;
}