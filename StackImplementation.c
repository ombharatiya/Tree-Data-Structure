#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 200
typedef struct node node;

/**
 * Creating a structure for a node of tree
**/
struct node {
    int data;
    node *left;
    node *right;
};

/**
 * Helper function to create new node in the tree
**/

node* newNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Function to create new stack of nodes
**/

node **createStack(int *top) {
    node **stack = (node**)malloc(sizeof(node*)*MAX_QUEUE_SIZE);
    *top = 0;
    return stack;
}

/**
 * Function to add (push) a new nodes in stack 
**/

void push(node **stack, int *top, node *root) {
    stack[++(*top)] = root;
}

/**
 * Function to remove (pop) a new nodes from the stack 
**/

node* pop(node **stack, int *top) {
    (*top)--;
    return stack[*top + 1];
}

/**
 * Main Driving Function
**/
void main() {
    int top;

    // Creating Node for Tree
    node* a = newNode(50);

    a->left = newNode(30);
    a->right = newNode(60);
    a->left->left = newNode(10);
    a->right->right = newNode(80);
    
    printf("STACK IMPLEMENTATION\n");
    
    // Creating Stack to store the nodes
    node **stack = createStack(&top);

    // Pushing all nodes of tree inside the stack
    printf("\nAdding %d into stack.", a->data);
    push(stack, &top, a);
    printf("\nAdding %d into stack.", a->left->data);
    push(stack, &top, a->left);
    printf("\nAdding %d into stack.", a->right->data);
    push(stack, &top, a->right);
    printf("\nAdding %d into stack.", a->left->left->data);
    push(stack, &top, a->left->left);
    printf("\nAdding %d into stack.", a->right->right->data);
    push(stack, &top, a->right->right);

    printf("\nPopping out each of them one by one.\n");

    // Popping out each node to print
    while(top>0) {
        printf("%d ", pop(stack, &top)->data);
    }

}