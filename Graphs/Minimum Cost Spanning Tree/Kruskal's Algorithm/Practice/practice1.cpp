#include<iostream>
#include<vector>
using namespace std;

class DisjointSetUniont {
public:
    int n;
    vector<int> par, rank;

    DisjointSetUniont(int n) {
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
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
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
    DisjointSetUniont dsu(4);
    dsu.Union(1,2);
    dsu.getInfo();
    dsu.Union(1,3);
    dsu.getInfo();
    dsu.Union(1,0);
    dsu.getInfo();
    
    cout << dsu.find(1);

    dsu.getInfo();

    return 0;
}