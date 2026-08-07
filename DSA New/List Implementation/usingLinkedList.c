#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

typedef struct List
{
    Node *head;
    int size;
} List;

int insert(List *L, int pos, int val)
{
    if (pos < 0 || pos > L->size)
        return -1;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return 0;

    if (pos == 0)
    {
        newNode->next = L->head;
        L->head = newNode;
    } else {
        Node *temp = L->head;
        for(int i = 0; i<pos-1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    L->size++;
    return 1;
}

int delete(List *L, int pos)
{
    if (pos < 0 || pos >= L->size)
        return -1;

    Node *temp;
    if (pos == 0)
    {
        temp = L->head;
        L->head = temp->next;
    }
    else
    {
        Node *prev = L->head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }

        temp = prev->next;
        prev->next = temp->next;
    }

    free(temp);
    L->size--;

    return 1;
}

int getElement(List *L, int pos) {
    Node *temp = L->head;
    
    for(int i = 0; i<pos; i++) {
        temp = temp->next;
    }

    return temp->data;
}

int printList(List *L) {
    Node *temp = L->head;

    for(int i = 0; i<L->size; i++) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
        printf("NULL\n");
}

int main()
{

    return 0;
}

