#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
public:
    int u, v, wt;

    Edge(int u, int v, int wt)
        : u(u), v(v), wt(wt) {}

    bool operator<(const Edge &other) const {
        return wt < other.wt;
    }
};

class DSU {
public:
    vector<int> par, rank;

    DSU(int n) {
        for(int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB)
            return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }

    void getInfo() const {
        cout << "\nParent Array: ";
        for(int i : par)
            cout << i << " ";

        cout << "\nRank Array: ";
        for(int i : rank)
            cout << i << " ";

        cout << endl;
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int wt) {
        edges.emplace_back(u, v, wt);
    }

    int kruskalMST() {

        sort(edges.begin(), edges.end());

        DSU dsu(V);

        int mstWeight = 0;
        int edgeCount = 0;

        cout << "Edges in MST:\n";

        for(const auto &e : edges) {

            int parU = dsu.find(e.u);
            int parV = dsu.find(e.v);

            if(parU != parV) {

                dsu.unionByRank(e.u, e.v);

                mstWeight += e.wt;
                edgeCount++;

                cout << e.u
                     << " - "
                     << e.v
                     << " : "
                     << e.wt
                     << endl;

                if(edgeCount == V - 1)
                    break;
            }
        }

        dsu.getInfo();

        return mstWeight;
    }
};

int main() {

    Graph g1(4);

    g1.addEdge(0, 1, 10);
    g1.addEdge(0, 2, 6);
    g1.addEdge(0, 3, 5);
    g1.addEdge(1, 3, 15);
    g1.addEdge(2, 3, 4);

    cout << "\nKruskal MST Weight: "
         << g1.kruskalMST()
         << endl;

    return 0;
}