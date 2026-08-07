// Array Implementation of Stack

#include<stdio.h>
#define MAX 1000

typedef struct Stack {
    int data[MAX];
    int top;
}Stack;
 
void printStack(Stack *S) {
    if(S->top == -1) {
        printf("Empty Stack\n");
        return;
    }

    printf("----------\n");
    for(int i = S->top; i>=0; i--) {
        if(i == S->top) {
            printf("Top-> |%d|\n", S->data[i]);
            continue;
        } 
        printf("      |%d|\n", S->data[i]);
    }
    printf("----------\n");
}

void initStack(Stack *S) {
    S->top = -1;
}

void push(Stack *S, int val) {
    if(S->top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }

    S->top++;
    S->data[S->top] = val;
}

int pop(Stack *S) {
    if(S->top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }

    return S->data[S->top--];
}

int peek(Stack *S) {
    if(S->top == -1) {
        return -1;
    }
    return S->data[S->top];
}

int isEmpty(Stack *S) {
    return S->top == -1;
}

int size(Stack *S) {
    return S->top+1;
}

int main() {
    Stack S;
    initStack(&S);

    push(&S,10);
    push(&S,20);
    push(&S,20);
    push(&S,30);
    push(&S,40);
    push(&S,50);
    
    printf("Stack: \n");
    printStack(&S);

    printf("Stack After pop: \n");
    pop(&S);
    printStack(&S);

    printf("Peek: %d\n", peek(&S));

    if(isEmpty(&S))
        printf("Is Empty: True\n");
    else
        printf("Is Empty: False\n");
    
    printf("Size: %d\n", size(&S));

    return 0;
}