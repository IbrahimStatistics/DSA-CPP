#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int n;
    int *par;
    int *rank;
} DisjoinSetUnion;

DisjoinSetUnion* createDSU(int n) {
    DisjoinSetUnion* dsu = malloc(sizeof(DisjoinSetUnion));
    
    dsu->n = n;
    dsu->par = malloc(n * sizeof(int));
    dsu->rank = malloc(n * sizeof(int));

    for(int i = 0; i<n; i++) {
        *(dsu->par + i) = i;
        *(dsu->rank + i) = 0;
    }

    return dsu;
}

int find(int *par, int x) {
    if(par[x] == x) return x;

    return par[x] = find(par, par[x]);
}

void Union(int *par, int *rank, int a, int b) {
    int parA = find(par, a);
    int parB = find(par, b);
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

void getInfo(DisjoinSetUnion *DSU) {
    printf("Parent\n");
    for(int i = 0; i<DSU->n; i++) {
        printf("%d ", *(DSU->par + i));
    }

    printf("\n-------------\n");
    
    printf("Rank\n");
    for(int i = 0; i<DSU->n; i++) {
        printf("%d ", *(DSU->rank + i));
    }
}

int main() {
    DisjoinSetUnion dsu;
    DisjoinSetUnion *ds = createDSU(6);

    Union(ds->par, ds->rank, 2,0);
    Union(ds->par, ds->rank, 2,1);
    Union(ds->par, ds->rank, 2,3);
    Union(ds->par, ds->rank, 2,4);
    Union(ds->par, ds->rank, 2,5);

    getInfo(ds);

    return 0;
}