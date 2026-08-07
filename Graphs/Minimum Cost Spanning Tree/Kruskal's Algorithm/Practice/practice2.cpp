#include<iostream>
#include<algorithm>
#include<vector>
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
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    int kruskalMST(vector<vector<int>> edges) {
        sort(edges.begin(), edges.end());

        int mst = 0;
        for(auto edge : edges) {
            int wt = edge[0];
            int a = edge[1];
            int b = edge[2];

            int parA = find(a);
            int parB = find(b);

            if(parA!=parB) { // non cyclic
                mst+=wt;
                Union(a, b);
            } 
        }

        return mst;
    }

    void getInfo() {
        cout << "Parent: ";
        for(int i : par) cout << i << " ";
        cout << endl;

        cout << "Rank: ";
        for(int i : rank) cout << i << " ";
        cout << endl;
    }
};


int main() {
    DisjointSetUnion dsu(7);
    vector<vector<int>> edges = {
    {7, 0, 1},
    {5, 0, 3},
    {8, 1, 2},
    {9, 1, 3},
    {7, 1, 4},
    {5, 2, 4},
    {15, 3, 4},
    {6, 3, 5},
    {8, 4, 5},
    {9, 4, 6},
    {11, 5, 6}
    };

    cout << "Min Kruskal MST: " << dsu.kruskalMST(edges); 

    return 0;
}