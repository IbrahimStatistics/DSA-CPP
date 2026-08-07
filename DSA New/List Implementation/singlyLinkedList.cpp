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
    int size;

    List()
    {
        head = tail = nullptr;
        size = 0;
    }

    int length()
    {
        return size;
    }

    void printList() {
        Node *temp = head;
        while(temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
            cout <<"NULL" << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
           tail->next = newNode;
           tail = newNode; 
        }

        size++;
    }

    void pop_back()
    {
        if(tail == nullptr) {
            return;
        } else if(head == tail) {
            head = tail = nullptr;
        } else {
            Node *temp = head;

            while(temp->next != tail) {
                temp = temp->next;
            }

            delete tail;
            tail = temp;
            tail->next = nullptr;
        }

        size--;
    }

    void push_front(int val)
    {
    }

    void pop_front()
    {
    }

    void insert(int val, int pos)
    {
    }
};

int main()
{
    List L1;
    L1.push_back(10);
    L1.push_back(10);
    // L1.printList();
    // cout << L1.length();
    
    L1.pop_back();
    L1.printList();
    // cout << L1.length();
    
    return 0;
}