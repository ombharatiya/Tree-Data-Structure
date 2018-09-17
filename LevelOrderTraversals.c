#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 200
typedef struct node node;

/**
 * Creating a structure for a node
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

node **createStack(int *top) {
    node **stack = (node**)malloc(sizeof(node*)*MAX_QUEUE_SIZE);
    *top = 0;
    return stack;
}

void push(node **stack, int *top, node *root) {
    stack[++(*top)] = root;
}

node* pop(node **stack, int *top) {
    (*top)--;
    return stack[*top + 1];
}

/**
 * function to create new queue
**/
node **createQueue(int *front, int *rear) {
    node **queue = (node**)malloc(sizeof(node*)*MAX_QUEUE_SIZE);
    *front = 0;
    *rear = 0;
    return queue;
}

/**
 * function to add a node in the queue
**/
void enQueue(node **queue, int *rear, node *root) {
    queue[*rear] = root;
    (*rear)++;
}

/**
 * function to delete a node from the queue
**/
node* deQueue(node **queue, int *front) {
    (*front)++;
    return queue[*front-1];
}

/**
 * Levelorder traversal function using DFS ALgo(using queue) for a tree
**/
void printLevelorderReverse(node *root) {
    int rear, front;
    node **queue = createQueue(&front, &rear);
    node *temp = root;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        if(temp->left!=NULL) enQueue(queue, &rear, temp->left);
        if(temp->right!=NULL) enQueue(queue, &rear, temp->right);
        temp = deQueue(queue, &front);
    }
}




/**
 * Main Driving Function
**/
void main() {
    int top;

    node* a = newNode(50);
    a->left = newNode(30);
    a->right = newNode(60);
    a->left->left = newNode(10);
    a->right->right = newNode(80);
    // printf("\n");
    // printf("Height : %d ", height(a));
    // printf("\nInorder: ");
    // printInorder(a);
    // printf("\nPreorder :");
    // printPreorder(a);
    // printf("\nPostorder :");
    // printPostorder(a);
    // printf("\nLevelOrderRecusrsive :");
    // printLevelOrderRecusrsive(a);
    // printf("\nReverseLevelOrderRecusrsive :");
    // printReverseLevelOrderRecusrsive(a);
    // printf("\nLevelOrderDFS :");
    // printLevelorderDFS(a);
    // printf("\n");
    // printf("Root Node: %d ", a->data);


    printf("\nSTACK IMPLEMENTATION\n");
    
    node **stack = createStack(&top);
    push(stack, &top, a);
    push(stack, &top, a->left);
    push(stack, &top, a->right);
    push(stack, &top, a->left->left);
    push(stack, &top, a->right->right);

    while(top>0) {
        printf("%d ", pop(stack, &top)->data);
    }

}