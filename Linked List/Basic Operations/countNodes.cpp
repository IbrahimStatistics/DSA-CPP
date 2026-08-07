#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void countNodes() {
        Node* temp = head;
        int nodes = 0;

        while(temp!=NULL) {
            nodes++;
        }

        if(nodes!=0) {
            cout << "Nodes: " << nodes << endl;
        } else {
            cout << "Nodes: 0 \n Empty" << endl;
        }
    }

    void printLL() {
        Node* temp = head;
        while(temp!=NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
            cout << "null" << endl;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            // 1->2->3->4->NULL
            Node* temp = head;

            while(temp!=NULL) {

            }
        }
    }
};

int main() {
    List LL;
    LL.push_front(10);
    LL.push_front(20);
    LL.printLL();
    // LL.pop_back();

    return 0;
}