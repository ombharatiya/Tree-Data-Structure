#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
 * function to calculate the no of full nodes of a tree
 * A full node is a node which have both left and right node not NULL 
**/

bool checkIdentical(node *root1, node *root2) {
    int front1, rear1;
    int front2, rear2;
    node **queue1 = createQueue(&front1, &rear1);
    node **queue2 = createQueue(&front2, &rear2);
    node *temp1 = root1;
    node *temp2 = root2;

    while(temp1!=NULL && temp2!=NULL) {
        
        if(temp1->data != temp2->data) {
            return false;
        }
        
        if(temp1->left!=NULL && temp2->left!=NULL)  {
            enQueue(queue1, &rear1, temp1->left);
            enQueue(queue2, &rear2, temp2->left);
        }
        else if(temp1->left!=NULL || temp1->left!=NULL) {
             return false;
        }

        if(temp1->right!=NULL && temp2->right!=NULL)  {
            enQueue(queue1, &rear1, temp1->right);
            enQueue(queue2, &rear2, temp2->right);
        }
        else if(temp1->right!=NULL || temp1->right!=NULL) {
             return false;
        }

        temp1 = deQueue(queue1, &front1);
        temp2 = deQueue(queue2, &front2);
    }
    return true;
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

    node* b = newNode(50);
    b->left = newNode(30);
    b->right = newNode(20);
    b->left->left = newNode(10);
    b->left->right = newNode(60);
    b->right->left = newNode(70);
    b->left->right->left = newNode(80);

        //         50
        //       /    \
        //     30      20
        //    /  \    /   
        // 10    60  70    
        //      /
        //     80
    
    printf("\nAre them Identical? : %s",checkIdentical(a, b) ? "true" : "false");
    
}