#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;

    void dfsHelper(int src, vector<bool>& visited) {
        cout << src << " ";
        visited[src] = true;

        for(auto neigh : l[src]) {
            if(!visited[neigh]) {
                dfsHelper(neigh, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList() {
        for(int i = 0; i<V; i++) {
            cout << i << " : ";

            for(auto neighbour : l[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void bfs() {
        queue<int> Q;
        vector<bool> visited(V, false);
        Q.push(0);
        visited[0] = true;

        while(Q.size()>0) {
            int src = Q.front();
            cout << src << " ";
            Q.pop();

            for(auto neighbour : l[src]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    Q.push(neighbour);
                }    
            }
        }
        
    }

    void dfs() {
        int src = 0;
        vector<bool> visited(V, false);
        dfsHelper(src, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // g.printAdjList();    

    g.bfs();
    cout << endl;
    g.dfs();

    return 0;
}