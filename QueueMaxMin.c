#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 200
char* readline();
char** split_string(char*);

// Complete the solve function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//

/**
 * function to create new queue
**/
int *createQueue(int *front, int *rear, int *size) {
    int *queue = (int*)malloc(sizeof(int)*MAX_QUEUE_SIZE);
    *front = 0;
    *rear = 0;
    *size = 0;
    return queue;
}

/**
 * function to add a node in the queue
**/

void enQueue(int *queue, int *rear, int *size, int root) {
    queue[*rear] = root;
    (*size)++;
    (*rear)++;
}

/**
 * function to delete a node from the queue
**/
int deQueue(int *queue, int *front, int *size) {
    (*front)++;
    (*size)--;
    return queue[*front-1];
}


int* solve(int arr_count, int* arr, int queries_count, int* queries, int* result_count) {
    int front, rear, size, i, j, q, d, min, max, temp;
    // int *queue = createQueue(&front, &rear);
    
    int* result = malloc(queries_count * sizeof(int));
    int *queue;
    *result_count=0;
    
    // for(q=0;q<queries_count;q++) {
    //     printf("%d ", queries[q]);
    // }
    // for(i=0;i<arr_count;i++) {
    //     printf("%d ", arr[i]);
    // }

    for(q=0;q<queries_count;q++) {
        queue = createQueue(&front, &rear, &size);
        d = queries[q];
        // printf("\nd = %d\n",d);
        for(i=0;i<=arr_count-d;i++) {
            max = arr[i];
            // printf("(");
            for(j=i;j<i+d;j++) {
                if(arr[j]>max) {
                    max=arr[j];
                }
                // printf("%d ", max);
            }
            
            // printf(")");
            // printf("Max[%d] = %d |", i, max);
            enQueue(queue, &rear, &size, max);
        }
        // printf("\n");
        // printf("\nSIZE %d\n", size);
        min = deQueue(queue, &front, &size);
        // printf("(");
        // for(i=0;i<arr_count-d-1;i++) {
        //     temp = deQueue(queue, &front, &size);
        //     if(min>temp) {
        //         min = temp;
        //     }
        //     printf("%d ", min);
        // }
        while(size>0) {
            temp = deQueue(queue, &front, &size);
            if(min>temp) {
                min = temp;
            }
            // printf("%d ", min);
        }

        // printf(")");
        // printf("\nSIZE %d\n", size);
        result[(*result_count)++] = min;
    }
    for(i=0;i<queries_count;i++) {
        printf("%d $ ", result[i]);
    }
    printf("\n%d **", *result_count);
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(readline());

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + arr_itr);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + arr_itr) = arr_item;
    }

    int arr_count = n;

    int* queries = malloc(q * sizeof(int));

    for (int queries_itr = 0; queries_itr < q; queries_itr++) {
        char* queries_item_endptr;
        char* queries_item_str = readline();
        int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

        if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(queries + queries_itr) = queries_item;
    }

    int queries_count = q;

    int result_count;
    int* result = solve(arr_count, arr, queries_count, queries, &result_count);

    for (int result_itr = 0; result_itr < result_count; result_itr++) {
        fprintf(fptr, "%d", *(result + result_itr));

        if (result_itr != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
