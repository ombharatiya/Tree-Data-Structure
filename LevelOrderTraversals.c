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
    int top;
    int rear, front;
    node **queue = createQueue(&front, &rear);
    node **stack = createStack(&top);
    node *temp = root;
    while(temp!=NULL) {
        // printf("%d ", temp->data);
        push(stack, &top, temp);
        if(temp->right!=NULL) enQueue(queue, &rear, temp->right);
        if(temp->left!=NULL) enQueue(queue, &rear, temp->left);
        temp = deQueue(queue, &front);
    }

    while(top>0) {
        printf("%d ", pop(stack, &top)->data);
    }
}




/**
 * Main Driving Function
**/
void main() {

    node* a = newNode(50);
    a->left = newNode(30);
    a->right = newNode(20);
    a->left->left = newNode(10);
    a->left->right = newNode(60);
    a->right->right = newNode(80);
    a->right->left = newNode(70);

        //         50
        //       /    \
        //     30      20
        //    /  \    /   \
        // 10    60  70    80
    
    printf("\nLevelOrderReverse :");
    printLevelorderReverse(a);
    

}