#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 100
 
struct Node {
    char value[20];
    struct Node *left;
    struct Node *right;
};
 
struct Node* nodeStack[MAX];
int nodeTop = -1;
char opStack[MAX][5];
int opTop = -1;
 
int priceVal, discountVal, quantityVal;
 
struct Node* newNode(char val[]) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->value, val);
    temp->left = temp->right = NULL;
    return temp;
}
 
void pushNode(struct Node* n) { nodeStack[++nodeTop] = n; }
struct Node* popNode()        { return nodeStack[nodeTop--]; }
void pushOp(char op[])        { strcpy(opStack[++opTop], op); }
char* popOp()                 { return opStack[opTop--]; }
char* peekOp()                { return opStack[opTop]; }
 
int precedence(char op[]) {
    if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0) return 3;
    if (strcmp(op, "&&") == 0) return 2;
    if (strcmp(op, "||") == 0) return 1;
    return 0;
}
 
void buildTree() {
    char *op          = popOp();
    struct Node* right = popNode();
    struct Node* left  = popNode();
    struct Node* node  = newNode(op);
    node->left  = left;
    node->right = right;
    pushNode(node);
}
 
struct Node* constructTree(char tokens[][20], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(tokens[i], "(") == 0) {
            pushOp(tokens[i]);
        } else if (strcmp(tokens[i], ")") == 0) {
            while (opTop != -1 && strcmp(peekOp(), "(") != 0)
                buildTree();
            popOp();
        } else if (strcmp(tokens[i], "&&") == 0 ||
                   strcmp(tokens[i], "||") == 0 ||
                   strcmp(tokens[i], ">")  == 0 ||
                   strcmp(tokens[i], "<")  == 0) {
            while (opTop != -1 && strcmp(peekOp(), "(") != 0 &&
                   precedence(peekOp()) >= precedence(tokens[i]))
                buildTree();
            pushOp(tokens[i]);
        } else {
            pushNode(newNode(tokens[i]));
        }
    }
    while (opTop != -1) buildTree();
    return popNode();
}
 
int getValue(char var[]) {
    if (strcmp(var, "price")    == 0) return priceVal;
    if (strcmp(var, "discount") == 0) return discountVal;
    if (strcmp(var, "quantity") == 0) return quantityVal;
    return atoi(var);
}
 
int evaluate(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return getValue(root->value);
    int l = evaluate(root->left);
    int r = evaluate(root->right);
    if (strcmp(root->value, ">")  == 0) return l > r;
    if (strcmp(root->value, "<")  == 0) return l < r;
    if (strcmp(root->value, "&&") == 0) return l && r;
    if (strcmp(root->value, "||") == 0) return l || r;
    return 0;
}
 
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->value);
        inorder(root->right);
    }
}
 
int main() {
    printf("Enter Price    : "); scanf("%d", &priceVal);
    printf("Enter Discount : "); scanf("%d", &discountVal);
    printf("Enter Quantity : "); scanf("%d", &quantityVal);
 
    char tokens[][20] = {
        "(", "price",    ">", "200", ")", "&&",
        "(", "discount", ">", "10",  ")", "&&",
        "(", "quantity", ">", "5",   ")", "||",
        "(", "price",    "<", "100", ")"
    };
    int n = sizeof(tokens) / sizeof(tokens[0]);
 
    struct Node* root = constructTree(tokens, n);
 
    printf("\nInfix  : ");
    inorder(root);
    printf("\nResult : %s\n", evaluate(root) ? "TRUE" : "FALSE");
    return 0;
}
