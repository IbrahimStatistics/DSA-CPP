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

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if(head == nullptr) {
            cout << "Empty List" << endl;
        }

        Node* temp = head;
        int val = temp->data;

        head->next = head;
        delete temp;
    }

    int push_back() {

    }

    int pop_back() {

    }

    int search() {

    }

};

int main() {

    return 0;
}