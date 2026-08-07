// List Implementation using Array

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct List  {
    int data[MAX];
    int size;
} List;

void initList(List *L) {
    L->size = 0;
}

void insert(List *L, int pos, int val) {
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
    
    for(int i = pos; i<L->size; i++) {
        L->data[i] = L->data[i+1];
    }
    
    L->size--;
}

void printList(List *L) {
    for(int i = 0; i<L->size; i++) {
        printf("%d ", L->data[i]);
    }
        printf("\n");
}

int getElement(List *L, int pos) {
    if(L->size == 0) return -1;
    return L->data[pos];
}

int searchElement(List *L, int val) {
    for(int i = 0; i<L->size; i++) {
        if(L->data[i] == val) {
            return i;
        }
    }
    
    printf("Not found\n");
    return -1;
}

int main() {
    List *L = (List *)malloc(sizeof(List));
    initList(L);
    insert(L, 0, 23);
    insert(L, 1, 24);
    insert(L, 2, 25);
    insert(L, 3, 26);
    
    printf("After Insertion\n");
    printList(L);
    
    printf("After Deletion\n");
    delete(L, 3);
    printList(L);
    
    return 0;
}