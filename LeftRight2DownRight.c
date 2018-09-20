// converting a Left-Right Binary tree to Down-Right Binary Tree

#include<stdio.h>
#include<stdlib.h>
// #define MAX_QUEUE_SIZE 200
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
 * Inorder traversal recursive function for a tree
**/
void printInorder(node *root) {
    if(root==NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}


/**
 * recursive function for converting a Left-Right Binary tree to Down-Right Binary Tree
**/

void convertLeftRight2DownRight(node *root) {
    if(root==NULL) { 
        return;
    }
    convertLeftRight2DownRight(root->right);
    convertLeftRight2DownRight(root->left);
    if(root->left!=NULL) {
        root->left->right=root->right;
    }
    else root->left=root->right;
        
    root->right=NULL;
    // printf("\n");
    // printInorder(root);
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
    a->right->right = newNode(80);

        //         50                              320(50+30+20+70+150)
        //       /    \                          /       \
        //     30      20        -->          70(10+60)   150(70+80)
        //    /  \    /   \                  /  \        /   \
        // 10    60  70    80               0    0      0     0
        //      
        //       
    
    printf("\nBefore: ");
    printInorder(a);
    convertLeftRight2DownRight(a);
    printf("\nAfter: ");
    printInorder(a);

    
}