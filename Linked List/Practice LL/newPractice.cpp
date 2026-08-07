#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data1, Node* next1) {
		data = data1;
		next = next1;
	}

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class List {
	List() {
		cout << "Hello world!" << endl;
	}
};

int main() {
	vector<int> arr = {2,5,8,7};
	Node* y = new Node(arr[0],nullptr);
    cout << y->data << endl;
    cout << y->next << endl;

}