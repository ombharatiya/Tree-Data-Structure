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

int getHeightIterative(node *root) {
    if(root==NULL) return 0;
    int height = 0;
    while(root!=NULL) {
        
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
    a->right->left = newNode(70);
    a->left->right->left = newNode(80);

        //         50
        //       /    \
        //     30      20
        //    /  \    /   
        // 10    60  70    
        //      /
        //     80
    
    printf("\nHeight: %d",getHeightIterative(a));
    
}