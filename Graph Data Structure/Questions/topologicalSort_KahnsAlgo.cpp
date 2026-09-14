#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printAdjList() const {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int n : adj[i]) cout << n << " ";
            cout << '\n';
        }
    }

    void topoSort() const {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++)
            for (int v : adj[u])
                inDegree[v]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (inDegree[i] == 0) q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            for (int v : adj[u])
                if (--inDegree[v] == 0) q.push(v);
        }

        if ((int)ans.size() != V) {
            cout << "Cycle detected — no topological order exists.\n";
            return;
        }
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
};

int main() {
    cout << '\n';
    Graph g(6);   // nodes 0..5
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.printAdjList();
    cout << '\n';
    g.topoSort();
    
    cout << '\n';
    return 0;
}