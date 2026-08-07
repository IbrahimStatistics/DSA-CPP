// Create a singly linked list with integers and perform several operations like push front, push back, pop fron and pop back.

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
        next = nullptr;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        head = tail = nullptr;
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop_front()
    {
        Node *temp = head;

        if (head == nullptr)
        {
            tail = nullptr;
            cout << "Empty List" << endl;
        }
        else
        {
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    List LL;
    LL.push_front(10);
    LL.push_front(20);
    LL.printLL();

    LL.pop_front();
    LL.printLL();

    return 0;
}