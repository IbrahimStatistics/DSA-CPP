// Topological Sort using DFS
#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

    void dfs(int src, vector<bool>& vis, stack<int>& s) {
        vis[src] = true;

        for(int v : l[src]) {
            if(!vis[v]) {
                dfs(v, vis, s);
            }
        }

        s.push(src);
    }

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); // only directed edges
    }

    void topologicalSort() {
        int src = 0;
        vector<bool> visited(V, false);
        stack<int> s;

        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, visited, s);
            }
        }

        while(s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }

};

int main() {
    Graph g(6);

    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 3);

    cout << "Topological Sort: "; g.topologicalSort();

    return 0;
}