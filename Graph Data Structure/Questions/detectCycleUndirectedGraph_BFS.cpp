// Detect Cycle in an Undirected Graph using BFS
#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

    void dfsHelper(int src, vector<bool>& visited) {
        visited[src] = true;
        cout << src << " ";

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
            for(auto neigh : l[i]) {
                cout << neigh << " ";
            }

            cout << endl;
        } 
    }

    void bfs() {
        queue<int> Q;
        vector<bool> visited(V, false);

        Q.push(0);
        visited[0] = true;

        while(Q.size() > 0) {
            int src = Q.front();
            cout << src << " ";
            Q.pop();

            for(auto neigh : l[src]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    Q.push(neigh);
                }
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> visited(V, false);
        dfsHelper(src, visited);
    }

    bool detectCycleBFS(int src, int par, vector<bool>& visited) {
        queue<pair<int, int>> Q;
        Q.push({src, par});

        visited[src] = true;
        while(Q.size() > 0) {
            int currNode = Q.front().first;
            int currParent = Q.front().second;
            Q.pop();

            for(auto neigh : l[currNode]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    Q.push({neigh, currNode});
                } else if(neigh != currParent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                if(detectCycleBFS(i, -1, visited))
                    return true; 
            }
        }

        return false;
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    cout << "BFS Traversal: "; g.bfs();
    cout << endl;

    cout << "DFS Traversal: "; g.dfs();
    cout << endl;
    
    cout << "Is Cyclic: "; 
    if(g.isCyclic())
        cout << "True";
    else 
        cout << "False";
    cout << endl;

    return 0;
}