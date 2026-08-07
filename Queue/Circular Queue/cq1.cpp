#include<iostream>
using namespace std;

class circularQueue {
    int* queue;
    int front = 0;
    int rear = -1;
    int capacity;
    int currSize = 0;
    
public:
    circularQueue(int size) {
        currSize = 0;
        capacity = size;
        queue = new int[size];
    }

    ~circularQueue() {
        delete[] queue;
    }

    void push(int x) {

        // Overflow
        if(currSize == capacity) {
            cout << "Queue Overflow\n";
            return;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = x;
        currSize++;
    }

    void pop() {

        // Underflow
        if(currSize == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        front = (front + 1) % capacity;
        currSize--;
    }

    void print() {

        if(currSize == 0) {
            cout << "Queue Empty\n";
            return;
        }

        for(int i = 0; i < currSize; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }

        cout << endl;
    }

};

int main() {

    circularQueue Q1(6);

    Q1.push(1);
    Q1.push(3);
    Q1.push(5);
    Q1.push(7);
    Q1.push(9);
    Q1.push(11);

    Q1.print();

    Q1.pop();
    Q1.print();

    Q1.pop();
    Q1.print();

    Q1.pop();
    Q1.print();

    return 0;
}