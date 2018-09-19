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
 * recursive function for converting a normal Ninary tree to Sum Binary Tree
**/

int convert2SumTreeUtil(node *root) {
    // if(root->left!=NULL && root->right!=NULL) return root->left->data + root->right->data;
    if(root==NULL) return 0;
    // if(root->left==NULL && root->right==NULL) return root->data;
    
    int oldData = root->data;
    root->data =convert2SumTreeUtil(root->left) + convert2SumTreeUtil(root->right);
    return (root->data + oldData);
}
void convert2SumTree(node *root) {
    if(root!=NULL) { 
        root->data = convert2SumTreeUtil(root);
    }
    
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
    convert2SumTree(a);
    printf("\nAfter: ");
    printInorder(a);

    
}