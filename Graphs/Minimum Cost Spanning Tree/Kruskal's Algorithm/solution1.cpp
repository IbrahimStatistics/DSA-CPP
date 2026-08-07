#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void Union(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA]>rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    void getInfo() {
        cout << "Parent: ";
        for(auto i : par) cout << i << " ";
        cout << endl;
        
        cout << "Rank: ";
        for(auto i : rank) cout << i << " ";
        cout << endl;
    }

    int kruskalMst(vector<vector<int>> edges) {
        sort(edges.begin(), edges.end());
        
        int mstCost = 0;

        for(auto edge : edges) {
            int wt = edge[0];
            int U  = edge[1];
            int V  = edge[2];

            int parU = find(U);
            int parV = find(V);

            if(parU != parV) {
                mstCost+=wt;
                Union(U,V);
            }
        }
        
        return mstCost;
    }
};

int main() {
    DisjointSetUnion dsu(4);

    vector<vector<int>> edges = {
        {10,0,1},
        {6,0,2},
        {5,0,3},
        {15,1,3},
        {4,2,3}
    };

    cout << "MST using Kruskal's Algorithm: " << dsu.kruskalMst(edges) << endl;
    
    dsu.getInfo();

    return 0;
}