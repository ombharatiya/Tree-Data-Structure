#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_HEAP_CAPACITY 100
#define sq(x) x*x
// int heap[MAX_HEAP_CAPACITY], size;
int size;
int capacity = MAX_HEAP_CAPACITY;
int *heap = NULL;
// int *heap = (int)malloc(sizeof(int)*MAX_HEAP_CAPACITY);

int init(int capacity) {
    heap = (int*)malloc(capacity*sizeof(int));
    size=0;
}

int getLeftChildIndex(int parentIndex) { return 2*parentIndex+1;}
int getRightChildIndex(int parentIndex) { return 2*parentIndex+2;}
int getParentIndex(int childIndex) { return (childIndex-1)/2;}

bool hasLeftChild(int parentIndex) { return (getLeftChildIndex(parentIndex)<size)?true:false;}
bool hasRightChild(int parentIndex) { return (getRightChildIndex(parentIndex)<size)?true:false;}
bool hasParent(int childtIndex) { return (getParentIndex(childtIndex)>=0)?true:false;}

int getLeftChild(int parentIndex) { return heap[getLeftChildIndex(parentIndex)];}
int getRightChild(int parentIndex) { return heap[getRightChildIndex(parentIndex)];}
int getParent(int childIndex) { return heap[getParentIndex(childIndex)];}

void swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1]=heap[index2];
    heap[index2]=temp;
}

void ensureExtraCapacity() {
    int i;
    if(size>=capacity) {
        capacity*=2;
        int *newHeap = (int*)malloc(capacity*sizeof(int));

        for(i=0;i<size;i++) {
            newHeap[i]=heap[i];
        }
        heap = newHeap;
    }
}

void heapifyUp() {
    int index = size-1;
    while(hasParent(index) && getParent(index)>heap[index]) {
        swap(index, getParentIndex(index));
        index = getParentIndex(index);
    }
}

void heapifyDown() {
    int index = 0;
    while(hasLeftChild(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && getRightChild(index)<getLeftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }
        if(heap[index]>=heap[smallerChildIndex]) {
            swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }
        else break;
    }
}


int peek() {
    if(size==0) return -1;
    else return heap[0];
}

int poll() {
    if(size==0) return -1;
    int res = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown();
    return res;
}
void insert(int value) {
    ensureExtraCapacity();
    heap[size] = value;
    size++;
    heapifyUp();
}

void main() {
    // printf("%d",sq(2+3));
    // printf("\n%d",sq(5+3+1));
    // int arr[] = {2,3,4,5,6};
    // printf("\n%u %u %u\n", arr, &arr[0], &arr);
    printf("\nInitiating Heap...");
    init(capacity);
    printf("\nInserting new element...");
    insert(4);
    printf("\nInserting new element...");
    insert(8);
    printf("\nInserting new element...");
    insert(3);
    printf("\nInserting new element...");
    insert(0);
    printf("\nInserting new element...");
    insert(7);
    printf("\nInserting new element...");
    insert(5);
    printf("\nInserting new element...");
    insert(1);
    printf("\nInserting new element...");
    insert(9);

    printf("\nThe root node is: %d", peek());
    printf("\nThe Sorted numbers are: ");

    while(size>0){
        printf("%d ", poll());
    }

}