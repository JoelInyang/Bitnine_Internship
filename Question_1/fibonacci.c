#include <stdio.h>
#include <stdlib.h>


typedef enum TypeTag{
    ADD,
    SUB,
    MUL,
    DIV
    }TypeTag; //TypeTag contains enumerations of operations involved

typedef struct Node{ // Node is a struct that contains multiple data types which are "TypeTag" and "Union"
    TypeTag type;
    union { // the union construct makes it possible for the program to run either and int or a struct but if contains operations will run any of the operations involved
        int value;
        struct {
            struct Node* left; // Left on the expression tree/calculation sides
            structNod* right; // Right on the e expression tree/calculation sides
        }operands; // The name of this particular structure
    }data;
}Node;
Node* createNode(TypeTag type) { //this declares a function and takes TypeTag(which contains the operations) as an argument and return a pointer to the node struct
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->data.operands.left = NULL;
    newNode->data.operands.right = NULL;
    return newNode;
}

void calculate(Node* node) { //this returns a void(nothing), it takes a node argument which returns a pointer to the Node structure
    if (node == NULL) { //if the node is null return nothing which means the node doesnt have an operation value
        return;
    }
    //node here refers to an expression denotes an operation(addition or subtraction) or a value(like numbers)
    switch (node->type) {
        case ADD:
            calculate(node->data.operands.left); //calculate here is a recursive function(that is a function that calls itself)
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value + node ->data.operands.right->data.value; //getting the left value of the operation and getting the right value of the operation then performing the ADD operation then assigning it to the node value.
            break;
        case SUB:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value - node->data.operands.right->data.value; //getting the left value of the operation and getting the right value of the operation then performing the SUB operation then assigning it to the node value.
            break;
        case MUL:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value * node->data.operands.right->data.value; //getting the left value of the operation and getting the right value of the operation then performing the MUL operation then assigning it to the node value.
            break;
        case DIV:
            calculate(node->data.operands.left);
            calculate(node->data.operands.right);
            node->data.value = node->data.operands.left->data.value / node->data.operands.right->data.value; //getting the left value of the operation and getting the right value of the operation then performing the DIV operation then assigning it to the node value.
            break;
    }
}


int main() { //the main function is the entry point of every C program
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    Node* add = createNode(ADD); //am using the createNode function i defined earlier to create a new node, using the Node structure defined earlier too and assigning to a pointer variable add
    add->data.operands.left = createNode(ADD); // creates a new node in the left operand of the data union, where this new node now contains it own left and right operands as well, making it a nested node still using the data struct
    add->data.operands.left->data.operands.left = createNode(ADD); //creates a new ADD node and assign it to the nested left operand(that is the left operand of the left operand of the add node)
    add->data.operands.left->data.operands.left->data.value = num1; // assigning the value of the left operand of the left operand to 1
    add->data.operands.left->data.operands.right = createNode(ADD); // creates a new node and assign it to the right operand of the left operand of the add node
    add->data.operands.left->data.operands.right->data.value = num2; //assigning the value of the right operand of the left operand of the add variable to 1
    add->data.operands.right = createNode(ADD);
    add->data.operands.right->data.operands.left = createNode(ADD);
    add->data.operands.right->data.operands.left->data.value = num1;
    add->data.operands.right->data.operands.right = createNode(ADD);
    add->data.operands.right->data.operands.right->data.value = num2;



    Node* mul = createNode(MUL); // am using the createNode function i defined earlier to create a new node, using the Node structure defined earlier too and assigning to a pointer to a variable called mul
    mul->data.operands.left = createNode(MUL); // creates a new node in the left operand of the data union, where  this new node now contains it own left and right operands as well
    mul->data.operands.left->data.operands.left = createNode(MUL);
    mul->data.operands.left->data.operands.left->data.value = 1;
    mul->data.operands.left->data.operands.right = createNode(MUL);
    mul->data.operands.left->data.operands.right->data.value = 1;
    mul->data.operands.right = createNode(MUL);
    mul->data.operands.right->data.operands.left = createNode(MUL);
    mul->data.operands.right->data.operands.left->data.value = 1;
    mul->data.operands.right->data.operands.right = createNode(MUL);
    mul->data.operands.right->data.operands.right->data.value = 0;

    Node* sub = createNode(SUB);
    sub->data.operands.left = mul;
    sub->data.operands.right = add;

    Node* fibo = createNode(SUB);
    fibo->data.operands.left = sub;
    fibo->data.operands.right = NULL;

    calculate(add); // calculates the values of the nodes using the calculate function i created earlier
    calculate(mul); // calculates the values of the nodes using the calculate function i created earlier
    calculate(sub); // calculates the values of the nodes using the calculate function i created earlier
    calculate(fibo); // calculates the values of the nodes using the calculate function i created earlier





    printf("add : %d\n", add->data.value); // prints the value
    printf("mul : %d\n", mul->data.value); // prints the value
    printf("sub : %d\n", sub->data.value); // prints the value
    printf("fibo : %d\n", fibo->data.value); // prints the value

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
