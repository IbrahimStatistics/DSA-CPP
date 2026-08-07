#include<iostream> 
#include<vector>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

int main()  {
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    for (const vector<Edge>& i : g) {
    for (const Edge& j : i) {
        cout << j.v << "-" << j.wt << "- ";  // or j.someMember
    }
    // cout << endl;
}


    return 0;
}