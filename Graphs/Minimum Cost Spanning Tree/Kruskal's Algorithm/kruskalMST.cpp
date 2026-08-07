#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
public:
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    // Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {}

    bool operator<(const Edge &other) const {
        return this->wt < other.wt;
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;
    vector<int> par, rank;

    Graph(int V) {
        this->V = V;
        for(int i = 0; i<V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u,v,wt));
    }

    int find(int x) {
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    void Union (int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    int kruskalMST() {
        sort(edges.begin(), edges.end());
        int mst = 0;
        int count = 0;

        for(auto i : edges) {
            int u = i.u;
            int v = i.v;
            int wt = i.wt;
            int count = 0;

            int parU = find(u);
            int parV = find(v);

            if(count == V-1) break;

            if(parU != parV) {
                mst += wt;
                Union(u, v);
                count++;
            }
        }

        return mst;
    }

    void getInfo () const {
        cout << "Parent: ";
        for(int i : par) cout << i << " ";
        cout << endl;

        cout << "Rank: ";
        for(int i : rank) cout << i << " ";
        cout << endl;
    }
};

class DisjointSetUnion {
public:
    int n;
    vector<int> par, rank;

    DisjointSetUnion(int n) {
        this->n = n;
        for(int i = 0; i<n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void Union(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }
};

int main() {

    Graph g1(4);
    g1.addEdge(0,1,10);
    g1.addEdge(0,2,6);
    g1.addEdge(0,3,5);
    g1.addEdge(1,3,15);
    g1.addEdge(2,3,4);

    cout << "Kruskal MST: " << g1.kruskalMST() << endl;
    g1.getInfo();

    return 0;
}