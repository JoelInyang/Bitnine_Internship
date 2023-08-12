#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV
} TypeTag;

typedef struct Node {
    TypeTag type;
    union {
        int value;
        struct {
            struct Node* left;
            struct Node* right;
        } operands;
    } data;
} Node;

Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->data.operands.left = NULL;
    newNode->data.operands.right = NULL;
    return newNode;
}

void calc(Node* node) {
    if (node == NULL) {
        return;
    }

    switch (node->type) {
        case ADD:
            calc(node->data.operands.left);
            calc(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value + node->data.operands.right->data.value;
            break;
        case SUB:
            calc(node->data.operands.left);
            calc(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value - node->data.operands.right->data.value;
            break;
        case MUL:
            calc(node->data.operands.left);
            calc(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value * node->data.operands.right->data.value;
            break;
        case DIV:
            calc(node->data.operands.left);
            calc(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value / node->data.operands.right->data.value;
            break;
    }
}

int main() {
    Node* add = makeFunc(ADD);
    add->data.operands.left = makeFunc(ADD);
    add->data.operands.left->data.operands.left = makeFunc(ADD);
    add->data.operands.left->data.operands.left->data.value = 1;
    add->data.operands.left->data.operands.right = makeFunc(ADD);
    add->data.operands.left->data.operands.right->data.value = 1;
    add->data.operands.right = makeFunc(ADD);
    add->data.operands.right->data.operands.left = makeFunc(ADD);
    add->data.operands.right->data.operands.left->data.value = 1;
    add->data.operands.right->data.operands.right = makeFunc(ADD);
    add->data.operands.right->data.operands.right->data.value = 0;

    Node* mul = makeFunc(MUL);
    mul->data.operands.left = makeFunc(MUL);
    mul->data.operands.left->data.operands.left = makeFunc(MUL);
    mul->data.operands.left->data.operands.left->data.value = 1;
    mul->data.operands.left->data.operands.right = makeFunc(MUL);
    mul->data.operands.left->data.operands.right->data.value = 1;
    mul->data.operands.right = makeFunc(MUL);
    mul->data.operands.right->data.operands.left = makeFunc(MUL);
    mul->data.operands.right->data.operands.left->data.value = 1;
    mul->data.operands.right->data.operands.right = makeFunc(MUL);
    mul->data.operands.right->data.operands.right->data.value = 0;

    Node* sub = makeFunc(SUB);
    sub->data.operands.left = mul;
    sub->data.operands.right = add;

    Node* fibo = makeFunc(SUB);
    fibo->data.operands.left = sub;
    fibo->data.operands.right = NULL;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    printf("add : %d\n", add->data.value);
    printf("mul : %d\n", mul->data.value);
    printf("sub : %d\n", sub->data.value);
    printf("fibo : %d\n", fibo->data.value);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}

