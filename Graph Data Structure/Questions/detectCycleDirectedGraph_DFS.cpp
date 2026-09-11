#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<list<int>> l;
    bool directed;

    void dfsHelper(int src, vector<bool>& visited) {
        visited[src] = true;
        cout << src << " ";
        for (int neigh : l[src])
            if (!visited[neigh])
                dfsHelper(neigh, visited);
    }

    bool isCycleDirDFS(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;
        for (int neigh : l[src]) {
            if (!vis[neigh]) {
                if (isCycleDirDFS(neigh, vis, recPath)) return true;
            } else if (recPath[neigh]) {
                return true;
            }
        }
        recPath[src] = false;
        return false;
    }

public:
    Graph(int V, bool directed = false) : V(V), l(V), directed(directed) {}

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (!directed) l[v].push_back(u);
    }

    void dfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i]) dfsHelper(i, visited);
    }

    void bfs() {
        vector<bool> vis(V, false);
        for (int s = 0; s < V; s++) {
            if (vis[s]) continue;
            queue<int> q;
            q.push(s);
            vis[s] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                cout << cur << " ";
                for (int nb : l[cur])
                    if (!vis[nb]) { vis[nb] = true; q.push(nb); }
            }
        }
    }

    bool isCycle() {
        if (directed) {
            vector<bool> vis(V, false), recPath(V, false);
            for (int i = 0; i < V; i++)
                if (!vis[i] && isCycleDirDFS(i, vis, recPath)) return true;
            return false;
        }
        // undirected cycle detection via union-find or parent-tracking DFS
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS Traversal: "; g.bfs();
    cout << endl;

    cout << "DFS Traversal: "; g.dfs();
    cout << endl;

    return 0;
}