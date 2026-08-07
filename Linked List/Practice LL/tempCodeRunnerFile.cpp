#include<iostream>
#include<vector>
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

    // Member functions (Methods)

    void printLL() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
            cout << "nullptr";
    }

    int length() {
        Node* temp = head;
        int length = 0;

        while(temp) {
            length++;
            temp = temp->next;
        }

        return length;
    }

    int push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        newNode = head;
    }