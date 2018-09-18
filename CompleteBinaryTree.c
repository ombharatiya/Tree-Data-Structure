#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
 * Function to find the depth of the tree
**/
int getDepth(node *root) {
    if(root==NULL) return 0;
    else {
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        return (l > r ? l+1 : r+1);
    } 
    // else return (getDepth(root->left) > getDepth(root->right) ? getDepth(root->left)+1 : getDepth(root->right)+1);
}

bool isCompleBinaryTreeUtil(node *root, int d, int level) {
    if(root==NULL) return false;

    if(root->left==NULL && root->right==NULL) {
        return (d==level+1);
    }
    return (isCompleBinaryTreeUtil(root->left, d, level+1) && isCompleBinaryTreeUtil(root->right, d, level+1));
}

bool isCompleteBinaryTree(node *root) {
    int d = getDepth(root);
    return isCompleBinaryTreeUtil(root, d, 0);
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
    
    node* b = newNode(50);
    b->left = newNode(30);
    b->right = newNode(20);
    b->left->left = newNode(10);
    b->left->right = newNode(60);
    b->right->left = newNode(70);
    b->right->right = newNode(80);

        //         50
        //       /    \
        //     30      20
        //    /  \    /  \
        // 10    60  70   80
    
    // printf("\nPre-Order Iterative: ");
    // preOrderIterative(a);
    // printf("\nIn-Order Iterative: ");
    // inOrderIterative(a);
    // printf("\nPost-Order Iterative: ");
    // postOrderIterative(a);

    printf("\nDepth : %d", getDepth(a));
    printf("\nIs Complete Binary Tree? : %s", isCompleteBinaryTree(a)?"True":"False");

    printf("\nDepth : %d", getDepth(b));
    printf("\nIs Complete Binary Tree? : %s", isCompleteBinaryTree(b)?"True":"False");
}