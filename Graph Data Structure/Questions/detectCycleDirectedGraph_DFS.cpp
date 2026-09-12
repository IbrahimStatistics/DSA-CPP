#include<bits/stdc++.h>
using namespace std;

class Graph { 
private:
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    bool isCycleDirDFS(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for(auto v : l[src]) {
            if(!vis[v]) {
                if(isCycleDirDFS(v, vis, recPath)) {
                    return true;
                }
            } else if(recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    bool dfs() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        int src = 0;

        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDirDFS(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    cout << endl;
    
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    cout << g.dfs();
    
    cout << endl;
    return 0;
}