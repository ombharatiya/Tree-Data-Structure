#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    struct ListNode* next;
    int data;
}ListNode;

ListNode* getNewListNode(int data) {
    ListNode *newListNode = (ListNode*) malloc(sizeof(ListNode));
    newListNode->data = data;
    newListNode->next = NULL;
    return newListNode;
}

/**
 * This method is to insert a ListNode at the beginning of the linked list
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
 * 
 * This method is to insert a ListNode at the end of the linked list
 **/
void insert_end(ListNode** head, int data) {
    ListNode* newListNode = getNewListNode(data);
    ListNode* curr_ListNode = (*head);
    if(!(*head)) {
        (*head) = newListNode;
    }
    else {
        while(curr_ListNode->next) {
            curr_ListNode = curr_ListNode->next;
        }
        curr_ListNode->next = newListNode;
    }
    return;
}

/**
 * This method is to insert a ListNode at any specific position(starting with 1 at head ListNode) of the linked list
 **/
void insert_pos(ListNode** head, int data, int pos) {
    ListNode* newListNode = getNewListNode(data);
    ListNode* curr_ListNode = (*head);
    ListNode* prev_ListNode = NULL;
    if(!(*head) && pos!=1) {
        printf("Feeding Wrong index for NULL List\nPlease feed location 1");
    }
    else if(pos==1) {
        newListNode->next = (*head);
        (*head) = newListNode;
    }
    else {
        while(--pos) {
            prev_ListNode = curr_ListNode;
            curr_ListNode = curr_ListNode->next;
        }
        prev_ListNode->next = newListNode;
        newListNode->next = curr_ListNode;
    }
    return;
}

/**
 * This method is to delete the first occuring ListNode with the given value from the Linked List
**/

void delete_ListNode(ListNode** head, int value) {
    ListNode *prev,*temp;
    ListNode *current = (*head);
    if(!(*head)) {
        printf("NULL Linked List Passed\nNothing to delete");
    }
    else {
        while(current) {
            if(current->data == value) {
                temp = current;
                prev->next = current->next;
                printf("ListNode %d has been successfully deleted\n", temp->data);
                free(temp);
                break;
            }
            prev = current;
            current = current->next;
        }
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
 * This method is to search a ListNode by its value in the linked list
 **/
int search_ListNode(ListNode **head, int key) {
    ListNode *curr_ListNode = (*head);
    int count = 1;
    while(curr_ListNode){
        if(curr_ListNode->data == key) {
            printf("\n%d has successfully found at position %d", key, count);
            return count;
        }
        count++;
        curr_ListNode = curr_ListNode->next;
    }
    printf("\n%d could not be found in the Linked List", key);
    return -1;
}

/** 
 * This method is to search a ListNode by its value in the linked list using recursive method
 **/
int search_ListNode_rec(ListNode **head, int key) {
    if(!(*head)) {
        printf("\n%d could not found\n", key);
        return -100;
    } 
    if((*head)->data==key) return 1;

    return 1 + search_ListNode_rec(&((*head)->next), key);
}

/** 
 * This method is to reverse a linked list
 **/

void reverse_list(ListNode **head) {
    ListNode *prev = NULL, *next;
    ListNode *curr_ListNode = (*head);
    if(!(*head)) return;
    while(curr_ListNode){
        next = curr_ListNode->next;
        curr_ListNode->next = prev;
        prev = curr_ListNode;
        curr_ListNode = next;
    }
    (*head) = prev;
    return;
}

/** 
 * This method is to reverse a linked list using recursive approach
 **/

void reverse_list_rec(ListNode **head) {
    ListNode *first, *rest;
    if(!(*head)) return;
    first = (*head);
    rest = first->next;
    if(rest == NULL) return;

    reverse_list_rec(&rest);
    first->next->next = first;
    first->next = NULL;

    (*head) = rest;
    return;
}
/** 
 * This method is to get the length of the linked list using recursive approach
 **/
int getLength(ListNode **head) {
    if(!(*head)) {
        return 0;
    }
    
    return 1 + getLength(&((*head)->next));
}

int main() {
    ListNode *head = NULL;
    insert_begin(&head, 10);
    insert_begin(&head, 30);
    insert_begin(&head, 30);
    insert_begin(&head, 60);
    insert_begin(&head, 20);
    display_list(head);
    printf("\nLength of LL : %d", getLength(&head));
    printf("\nSearching %d in Linked List...\nFound at Position : %d",8, search_ListNode_rec(&head, 8));
    printf("\nSearching %d in Linked List...\nFound at Position : %d",57, search_ListNode_rec(&head, 57));
    // printf("Creating A New LL: %p", head);

    return 0;
}