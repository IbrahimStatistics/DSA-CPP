#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }

public:
    void reverseLL() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr!=NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        prev = head;
    }

    void printLL() {
        Node* temp = head;

        while(temp!=NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
            cout << "NULL" << endl;
    }
};

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;

    Node* head = n1;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr!=nullptr) {
        next = curr->next;  // store value of next node
        curr->next = prev;  // reverse the list
        prev = curr;        // move prev forward
        curr = next;        // move curr forward
    }

    head = prev;

    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
        cout << "NULL" << endl;

    return 0;
}