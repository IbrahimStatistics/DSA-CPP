// Create an array of size 4 and covert it into a linked list

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int newData) {
        data = newData;
        next = nullptr;
    }
};

Node* array_to_LL(const vector<int>& arr) {
    if(arr.size()==0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // same as above
    }

    return head;
}

int size(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

void printLL(Node* head) {
    int count = size(head);
    Node* temp = head;

    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
        cout << "nullptr" << endl;
}

int search(Node* head, int targetValue) {
    Node* temp = head;
    int position = 0;
    while(temp->data != targetValue) {
        position++;
        temp = temp->next;
    }
        return position;
}

int main() {
    vector<int> arr = {90,120,360,540};
    Node* head = array_to_LL(arr);
    // cout << head->data << endl;
    // printLL(head);
    // cout << search(head,540) << endl;

    

    return 0;
}