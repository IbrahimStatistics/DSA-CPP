#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
    vector<int> arr;

    void heapifyUp(int index) {
        while(index>0) {
            int par = (index-1)/2; // 0 indexing
            if(arr[index] > arr[par]) {
                swap(arr[index], arr[par]);
                index = par;
            } else {
                break;
            }
        }
    }

    void insert(int val) {
        arr.push_back(val); // [10,5,4,3,2,...., X=12]
        heapifyUp(arr.size()-1);
    }

    void heapifyDown(int index) {
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < arr.size() && arr[left] > arr[largest]) {
            largest = left;
        } 

        if(right < arr.size() && arr[right] > arr[largest]) {
            largest = right;
        }
        

        if(largest != index) {
            swap(arr[largest], arr[index]);
            heapifyDown(largest);
        }
    }

    void deleteRoot() {
        
    }

    void print() {
        for(int i : arr) cout << i << " ";
        cout << endl;
    }

};

int main() {
    Heap h1;
    
    // [5,4,3,1,10]

    h1.insert(5);
    h1.insert(4);
    h1.insert(3);
    h1.insert(1);
    h1.insert(10);

    h1.print();

    return 0;
}