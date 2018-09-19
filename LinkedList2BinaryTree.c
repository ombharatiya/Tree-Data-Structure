#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 200
typedef struct node node;

/**
 * Creating a structure for a node of Binary Tree
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
 * Creating a structure for a node of Linked List
**/
typedef struct ListNode {
    struct ListNode* next;
    int data;
}ListNode;

/**
 * Helper function to create new node in the Lenked List
**/

ListNode* getNewListNode(int data) {
    ListNode *newListNode = (ListNode*) malloc(sizeof(ListNode));
    newListNode->data = data;
    newListNode->next = NULL;
    return newListNode;
}

/**
 * This method is to insert a Node at the beginning of the linked list
 **/
void insert_begin(ListNode** head, int data) {
    ListNode* newListNode = getNewListNode(data);
    if(!(*head)) {
        (*head) = newListNode;
    }
    else {
        newListNode->next = (*head);
        (*head) = newListNode;
    }
    return;
}

/** 
 * This method is to display the linked list
 **/
void display_list(ListNode* head){
	ListNode* current_ListNode = head;
	printf("Linked List:\n");
	while(current_ListNode){
		printf("[%d]-->", current_ListNode->data);
		current_ListNode = current_ListNode->next;
	}
	printf("NULL\n");
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
 * function to print the tree in inorder
**/
void printInorder(node *root) {
    if(root==NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}


/**
 * function to convert a linked list into a binary tree (not BST)
**/
void convertLinkedList2BinaryTree(ListNode* head, node** root) {
    if(head==NULL)  {
        *root=NULL;
        return;
    }
    int front,rear;
    *root = newNode(head->data);
    node **queue = createQueue(&front,&rear);
    enQueue(queue, &rear, *root);
    head = head->next;

    while(head!=NULL) {
        
        node *temp = deQueue(queue, &front);
        
        temp->left = newNode(head->data);
        enQueue(queue, &rear, temp->left);
        head=head->next;

        if(head!=NULL) {
            temp->right = newNode(head->data);
            enQueue(queue, &rear, temp->right);
            head=head->next;
        }
    }
    // printInorder(*root);
}

/**
 * Main Driving Function
**/
void main() {
    

    // Crating a linked list first
    ListNode *head = NULL;
    insert_begin(&head, 10);
    insert_begin(&head, 30);
    insert_begin(&head, 40);
    insert_begin(&head, 60);
    insert_begin(&head, 20);
    insert_begin(&head, 80);
    insert_begin(&head, 50);
    insert_begin(&head, 12);
    display_list(head);
    
    //  [12]-->[50]-->[80]-->[20]-->[60]-->[40]-->[30]-->[10]-->NULL
    

    // Creating a tree node (empty)
    node *a;
    convertLinkedList2BinaryTree(head, &a);
    printf("\nThe Inorder Traversal Of the Converted Tree is: ");
    printInorder(a);

    
    //             12
    //           /    \
    //         50       80
    //        /  \     /  \
    //       20    60  40   30
    //      /
    //     10

    // The Inorder Traversal Of the Converted Tree is: 10 20 50 60 12 40 80 30

    
}