#include <stdio.h>
#include <stdlib.h>

/**
* FuncBuild - function that returns fibonnaci sequence based on arithemic operations
* FibCalc - function to calculate the result of a Node based on its operation type
* @TypeTag type - enumerated type 
* @num1 - integer value 1 
* @num2 - integer value 2
*/

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIB
} TypeTag;


typedef struct Node {
    TypeTag type;
    int num1;
    int num2;
    int result;
} Node;


/* function to create a new Node with the given type and operands and returns it. */
Node* FuncBuild(TypeTag type, int num1, int num2) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->num1 = num1;
    node->num2 = num2;
    return node;
}

/* function calculate the result of a Node based on its operation type.*/
void FibCalc(Node* node) {
    int result;
    switch(node->type) {
        case ADD:
            result = node->num1 + node->num2;
            break;
        case SUB:
            result = node->num2 - node->num1;
            break;
        case MUL:
            result = node->num1 * node->num2;
            break;
        case DIV:
            result = node->num1 / node->num2;
            break;
        case FIB:
            if (node->num1 == 0) {
                result = 0;
            } else if (node->num2 == 1) {
                result = 1;
            } else {
                int num1 = 0, num2 = 1, temp;
                int i;
                for (i = 2; i <= node->num1; i++) {
                    temp = num1 + num2;
                    num1 = num2;
                    num2 = temp;
                }
                result = num2;
            }
            break;
    }
    node->result = result;
}

int main() {
    /* create nodes for each arithmetic operation */
    Node *add = FuncBuild(ADD, 10, 6);
    Node *mul = FuncBuild(MUL, 5, 4);
    Node *sub = FuncBuild(SUB, 20, 16);
    Node *fibo = FuncBuild(FIB, sub->result, 0);

    /* Calculate the results of each node */ 
    FibCalc(add);
    FibCalc(mul);
    FibCalc(sub);
    FibCalc(fibo);

    /* print the results */ 
    printf("add : %d\n", add->result);
    printf("mul : %d\n", mul->result);
    printf("sub : %d\n", sub->result);
    printf("fibo : %d\n", fibo->result);

    return 0;
}