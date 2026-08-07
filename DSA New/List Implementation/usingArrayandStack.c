#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct List {
    int data[MAX];
    int size;
} List;

void initList(List *L) {
    L->size = 0;
}

void insert(List *L, int val, int pos) {
    if(pos<0 || pos>L->size) return;
    if(L->size == MAX) return;

    for(int i = L->size; i>pos; i--) {
        L->data[i] = L->data[i-1];
    }

    L->data[pos] = val;
    L->size++;
}

void delete(List *L, int pos) {
    if(pos<0 || pos>=L->size) return;
    if(L->size == 0) return;

    for(int i = pos+1; i<L->size ; i++) {
        L->data[i-1] = L->data[i];
    }

    L->size--;
}

void printList(List *L) {
    for(int i = 0; i<L->size; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int get(List *L, int pos) {
   return L->data[pos]; 
}

void searchList(List *L, int val) {
    for(int i = 0; i<L->size; i++) {
        if(L->data[i] == val) {
            printf("index: %d\n", i);
            return;
        }

        printf("Not found\n");
    }
}

int main() {
    List L;
    initList(&L);

    insert(&L, 23, 0);
    insert(&L, 24, 1);
    insert(&L, 25, 2);
    insert(&L, 26, 3);

    printList(&L);
    return 0;
}