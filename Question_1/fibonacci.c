#include <stdio.h>
#include <stdlib.h>

typedef enum Operation {
    ADD,
    SUB,
    MUL,
    DIV
} Operation;

typedef struct ExpressionNode {
    Operation op;
    union {
        int value;
        struct {
            struct ExpressionNode* left;
            struct ExpressionNode* right;
        } operands;
    } data;
} ExpressionNode;

ExpressionNode* createNode(Operation op) {
    ExpressionNode* newNode = (ExpressionNode*)malloc(sizeof(ExpressionNode));
    newNode->op = op;
    newNode->data.operands.left = NULL;
    newNode->data.operands.right = NULL;
    return newNode;
}

void calculate(ExpressionNode* node) {
    if (node == NULL) {
        return;
    }

    switch (node->op) {
        case ADD:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value + node->data.operands.right->data.value;
            break;
        case SUB:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value - node->data.operands.right->data.value;
            break;
        case MUL:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value * node->data.operands.right->data.value;
            break;
        case DIV:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value / node->data.operands.right->data.value;
            break;
    }
}

int main() {
    ExpressionNode* add = createNode(ADD);
    add->data.operands.left = createNode(ADD);
    add->data.operands.left->data.operands.left = createNode(ADD);
    add->data.operands.left->data.operands.left->data.value = 1;
    add->data.operands.left->data.operands.right = createNode(ADD);
    add->data.operands.left->data.operands.right->data.value = 1;
    add->data.operands.right = createNode(ADD);
    add->data.operands.right->data.operands.left = createNode(ADD);
    add->data.operands.right->data.operands.left->data.value = 1;
    add->data.operands.right->data.operands.right = createNode(ADD);
    add->data.operands.right->data.operands.right->data.value = 0;

    ExpressionNode* mul = createNode(MUL);
    mul->data.operands.left = createNode(MUL);
    mul->data.operands.left->data.operands.left = createNode(MUL);
    mul->data.operands.left->data.operands.left->data.value = 1;
    mul->data.operands.left->data.operands.right = createNode(MUL);
    mul->data.operands.left->data.operands.right->data.value = 1;
    mul->data.operands.right = createNode(MUL);
    mul->data.operands.right->data.operands.left = createNode(MUL);
    mul->data.operands.right->data.operands.left->data.value = 1;
    mul->data.operands.right->data.operands.right = createNode(MUL);
    mul->data.operands.right->data.operands.right->data.value = 0;

    ExpressionNode* sub = createNode(SUB);
    sub->data.operands.left = mul;
    sub->data.operands.right = add;

    ExpressionNode* fibo = createNode(SUB);
    fibo->data.operands.left = sub;
    fibo->data.operands.right = NULL;

    calculate(add);
    calculate(mul);
    calculate(sub);
    calculate(fibo);

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

