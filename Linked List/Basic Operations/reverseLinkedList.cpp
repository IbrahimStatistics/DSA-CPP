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
    Node* head;
    Node* tail;

    List() {
        head = tail = nullptr;
    }

    void printLL() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
            cout << "nullptr" << endl;
    }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp) {
        
    }
}

int main() {
    Node* newNode = new Node(10);
    
    return 0;
}