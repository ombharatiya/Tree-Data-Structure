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
 * Inorder traversal recursive function for a tree
**/
void printInorder(node *root) {
    if(root==NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
/**
 * Postorder traversal recursive function for a tree
**/
void printPostorder(node *root) {
    if(root==NULL) return;
    printInorder(root->left);
    printInorder(root->right);
    printf("%d ", root->data);
}
/**
 * Preorder traversal recursive function for a tree
**/
void printPreorder(node *root) {
    if(root==NULL) return;
    printf("%d ", root->data);
    printInorder(root->left);
    printInorder(root->right);
}

/**
 * Levelorder traversal function using DFS ALgo(using queue) for a tree
**/
void printLevelorderDFS(node *root) {
    int rear, front;
    node **queue = createQueue(&front, &rear);
    node *temp = root;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        if(temp->left!=NULL) enQueue(queue, &rear, temp->left);
        if(temp->right!=NULL) enQueue(queue, &rear, temp->right);
        temp = deQueue(queue, &front);
    }
    // printf("hello");
    // temp = root;
    // printf("\n%d ", root->data);
}

/**
 * Function to calculate Height from the given node
 * It will return the height of the tree if the node in the argument passed id root node
**/
int height(node *root) {
    if(root==NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if(lHeight>rHeight) return (lHeight+1);
    else return (rHeight+1);
}

/**
 * Levelorder traversal Utility function for printing a level using Recursive ALgo for a tree
**/
void printALevel(node *root, int level) {
    if(level == 0) return;
    if(root == NULL) return;
    if(level == 1) {
        printf("%d ", root->data);
    }
    else {
        printALevel(root->left, level-1);
        printALevel(root->right, level-1);
    }
}

/**
 * Levelorder traversal function using Recursive ALgo for a tree
**/
void printLevelOrderRecusrsive(node *root) {
    if(root==NULL) return;
    else {
        int h = height(root);
        for(int i=1; i<=h; i++) {
            printALevel(root, i);
        }
    }
}
/**
 * Reverse Levelorder traversal function using Recursive ALgo for a tree
**/
void printReverseLevelOrderRecusrsive(node *root) {
    if(root==NULL) return;
    else {
        int h = height(root);
        for(int i=h; i>0; i--) {
            printALevel(root, i);
        }
    }
}






/**
 * Main Driving Function
**/
void main() {
    node* a = newNode(50);
    a->left = newNode(30);
    a->right = newNode(60);
    a->left->left = newNode(10);
    a->right->right = newNode(80);
    printf("\n");
    printf("Height : %d ", height(a));
    printf("\nInorder: ");
    printInorder(a);
    printf("\nPreorder :");
    printPreorder(a);
    printf("\nPostorder :");
    printPostorder(a);
    printf("\nLevelOrderRecusrsive :");
    printLevelOrderRecusrsive(a);
    printf("\nReverseLevelOrderRecusrsive :");
    printReverseLevelOrderRecusrsive(a);
    printf("\nLevelOrderDFS :");
    printLevelorderDFS(a);
    printf("\n");
    printf("Root Node: %d ", a->data);
}