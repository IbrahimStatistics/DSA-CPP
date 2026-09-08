#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int> *l; // Dynamic array l of data type list<int>, *l is declaration for dynamic array

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V]; // set size of dynamic array to V
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList() {
        for(int i = 0; i<V; i++) {
            cout << i << " : ";
            for(int neigh : l[i]) {
                cout << neigh << " ";
            }

            cout << endl;
        }
    }
};

int main () {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();
    
    return 0;
}

