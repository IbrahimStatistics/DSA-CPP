#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct List {
    Node *top;
    int size;
}Stack;

void initStack(Stack *S) {
    S->top = NULL;
    S->size = 0;
}

Node* createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void printStack(Stack *S) {
    if(S->top == NULL) {
        printf("Empty Stack\n");
        return;
    }

    Node *temp = S->top;
    printf("----------\n");
    printf("Top-> |%d|\n", temp->data);
    temp = temp->next;
    
    while(temp) {
        printf("      |%d|\n", temp->data);
        temp = temp->next;
    }
    printf("----------\n");
}

void push(Stack *S, int val) {
    Node *newNode = createNode(val);

    if(S->top == NULL) {
        S->top = newNode;
    } else {
        newNode->next = S->top;
        S->top = newNode;
    }

    S->size++;
}

void pop(Stack *S) {
    if(S->top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    Node *temp = S->top;
    S->top = temp->next;
    free(temp);

    S->size--;
}

int size(Stack *S) {
    return S->size;
}

int peek(Stack *S) {
    if(S->top == NULL) {
        printf("Empty Stack\n");
        return -1;
    }
    return S->top->data;
}

int search(Stack *S, int target) {
    Node *temp = S->top;
    int pos = 0;

    while(temp) {
        if(temp->data == target) {
            return pos;
        }

        pos++;
        temp = temp->next;
    }

    printf("Not found\n");
    return -1;
}

void freeStack(Stack *S) {
    while(S->top) {
        Node *temp = S->top;
        S->top = S->top->next;
        free(temp);
    }
    S->size = 0;
}

int main() {
    Stack S;
    initStack(&S);

    printf("Stack after Insertion: \n");
    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);
    printStack(&S);

    printf("Peek Stack: %d\n", peek(&S));
    printf("Size of Stack: %d\n", size(&S));
    
    printf("\n");
    
    printf("Stack After Pop: \n");
    pop(&S);
    printStack(&S);
    
    printf("Peek Stack: %d\n", peek(&S));
    printf("Size of Stack: %d\n", size(&S));
    
    printf("\n");
    freeStack(&S);

    return 0;
}