#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }

};

class DoublyList {
public:
    Node *head;
    Node *tail;

    DoublyList() {
        head = tail = nullptr;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);

        if(head == nullptr) {
            head = tail = nullptr;
        } else {
            newNode->next = head;
            head->prev = newNode;
            newNode = head;
        }
    }
};


int main() {
    DoublyList dll;

    dll.push_front(10);

    Node temp = *dll.head;
    // cout << temp.data << endl;
    printf("%d", temp.data);

    return 0;
}