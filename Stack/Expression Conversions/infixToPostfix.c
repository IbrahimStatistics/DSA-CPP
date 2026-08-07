#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

typedef struct List {
    Node *top;
} Stack;

void initStack(Stack *S) {
    S->top = NULL;
}

Node *createNode(char val[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    strcpy(newNode->data, val);
    newNode->next = NULL;
    return newNode;
}

void push(Stack *S, char val[]) {
    Node *newNode = createNode(val);

    newNode->next = S->top;
    S->top = newNode;
}

void pop(Stack *S) {
    if (S->top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    Node *temp = S->top;
    S->top = temp->next;
    free(temp);
}

int empty(Stack *st) {
    if (st->top == NULL)
        return 1;

    return 0;
}

char *peek(Stack *st) {
    if (st == NULL || st->top == NULL) {
        printf("Error\n");
        return NULL;
    }

    return st->top->data;
}

int isOperand(char ch) {
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

int isOperator(char ch) {
    return (ch == '+' ||
            ch == '-' ||
            ch == '*' ||
            ch == '/' ||
            ch == '^');
}

int main() {
    Stack st;
    initStack(&st);

    char postfix[] = "ABC/+DEF-*G^++";

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            char op[2];
            op[0] = postfix[i];
            op[1] = '\0';

            push(&st, op);
        }
        else if (isOperator(postfix[i])) {
            char op1[100], op2[100], temp[100];
            char *p1, *p2;

            p1 = peek(&st);
            if (!p1) break;
            strcpy(op1, p1);
            pop(&st);

            p2 = peek(&st);
            if (!p2) break;
            strcpy(op2, p2);
            pop(&st);

            sprintf(temp, "(%s%c%s)", op2, postfix[i], op1);

            push(&st, temp);
        }
    }

    printf("\nGiven Postfix Expression: %s\n", postfix);

    printf("\nInfix Expression: %s\n\n", peek(&st));

    return 0;
}