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
 * function to calculate the no of leaf nodes of a Binary tree
 * A half node is a node which have neither left nor right node
**/


int getLeafNodes(node *root) {
    int front, rear;
    int count = 0;
    node **queue = createQueue(&front, &rear);
    node *temp = root;
    if(temp==NULL) return 0;
    while(temp!=NULL) {
        if(temp->left==NULL && temp->right==NULL) {
            count++;
        }
        else {
            if(temp->left!=NULL) enQueue(queue, &rear, temp->left);
            if(temp->right!=NULL) enQueue(queue, &rear, temp->right);
        }

        temp = deQueue(queue, &front);
    }
    return count;
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
    a->right->left = newNode(70);
    a->left->right->left = newNode(80);

        //         50
        //       /    \
        //     30      20
        //    /  \    /   
        // 10    60  70    
        //      /
        //     80
    
    printf("\nLeaf node count: %d",getLeafNodes(a));
    
}