#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

typedef struct DoublyList {
    Node *head;
    Node *tail;
    int size;

}DoublyList;

Node* createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void push_front(DoublyList *L, int val) {
    Node *newNode = createNode(val);
    
    if(L->head == NULL) {
        L->head = L->tail = newNode;
    } else {
        newNode->next = L->head;
        L->head->prev = newNode;
        L->head = newNode;
    }
    L->size++;
}

void printList(DoublyList *L) {
    Node *temp = L->head;
    while(temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
        printf("NULL\n");
}

int main() {
    DoublyList *L;

    push_front(L, 10);
    push_front(L, 20);
    push_front(L, 30);

    printf("After Insertion\n");
    printList(L);

    return 0;
}