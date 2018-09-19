// Convert a Binary Tree to a Logical AND Binary Tree

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
 * recursive function for converting a normal Ninary tree to Logical AND Binary Tree
**/
void convert2LogicalANDTree(node *root) {
    if(root==NULL) return;
    // if(root->left==NULL || root->right==NULL) return;
    // if(root->left!=NULL) convert2LogicalANDTree(root->left);
    // if(root->right!=NULL) convert2LogicalANDTree(root->right);

    
    convert2LogicalANDTree(root->left);
    convert2LogicalANDTree(root->right);
    if(root->left!=NULL && root->right!=NULL) root->data = root->left->data & root->right->data;
    
    // if(root->left!=NULL && root->right!=NULL) return convert2LogicalANDTree(root->left) && convert2LogicalANDTree(root->right);
}

/**
 * Main Driving Function
**/
void main() {

    node* a = newNode(1);
    a->left = newNode(1);
    a->right = newNode(0);
    a->left->left = newNode(0);
    a->left->right = newNode(1);
    a->right->left = newNode(1);
    a->right->right= newNode(1);

        //         1                               0
        //       /    \                         /    \
        //     1        0         --->        0        1
        //    /  \    /   \                  /  \    /   \
        //   0    1  1     1                0    1  1     1
        //     
        //     
    
    // printf("\nHalf node count: %d",getHalfNodes(a));
    printf("\nBefre: ");
    printInorder(a);
    convert2LogicalANDTree(a);
    printf("\nAfter: ");
    printInorder(a);

    
}