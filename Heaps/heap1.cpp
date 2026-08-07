#include<iostream>
#include<vector>
using namespace std;

class maxHeap {
public:
    vector<int> heap;

    void heapifyUp(int index) {
        while(index>0) {
            int par = (index-1)/2;

            if(heap[index] > heap[par]) {
                swap(heap[index], heap[par]);
                index = par;
            } else {
                break;
            }
        }
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    void heapifyDown(int index) {
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if(right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void deleteRoot() {
        if(heap.size() == 0) return;

        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    void print() {

        for(int x : heap) {
            cout << x << " ";
        }

        cout << endl;
    }

    void heapify(vector<int>& arr, int n, int index) {
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(arr, n, largest);
        }

    }

    void heapSort(vector<int> & arr) {
        int n = arr.size();

        for(int i = n/2 - 1; i>=0; i--) {
            heapify(arr, n, i);
        }   

        for(int i = n - 1; i>0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};


int main() {
    vector<int> arr = {4,10,3,5,1};

    maxHeap m1;
    m1.heapSort(arr);

    for(int i : arr) cout << i << " ";

    return 0;
}