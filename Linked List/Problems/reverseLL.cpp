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
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = nullptr;
    }

    int length()
    {
        int count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    int search(int target)
    {
        Node *temp = head;
        int pos = 0;

        while (temp != nullptr)
        {
            if ((temp->data) == target)
            {
                return pos;
            }
            else
            {
                pos++;
                temp = temp->next;
            }
        }

        return -1;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            Node *temp = head; // (1->2->3) => push_front(4) => (4->1->2->3)
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "Empty List" << endl;
        }
        else
        {
            head = head->next;
            delete temp;
        }

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            Node *temp = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Empty List \n";
            return;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
    }

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
            return;
        }
        else if (pos == this->length())
        {
            push_back(val);
            return;
        }
        else if (pos > (this->length()))
        {
            cout << "Position out of bounds";
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        // int count = -1;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void reverse_LL() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr!=nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        
        head = prev;
    }   

    void printLL()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    List LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);
    LL.push_back(4);

    cout << "Before reversing\n";
    LL.printLL();
    cout << endl;

    cout << "After reversing\n";
    LL.reverse_LL();
    LL.printLL();
    cout << endl;

    return 0;
}