#include <stdio.h>
#define MAX 5

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} queue;

int is_full(queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int is_empty(queue* q) {
    return (q->front == q->rear);
}

void enqueue(queue* q, int val) {
    if (is_full(q)) {
        printf("Queue is full, Dequeue an element.\n");
    } else if (q->front == -1 && q->rear == -1){
        q->rear = q->front = 0;
        q->arr[q->rear] = val;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = val;
    }
}

void dequeue(queue* q) {
    if (is_empty(q)) {
        if (!(q->front == -1 && q->rear == -1)) {
            q->rear = q->front = -1;
        } else {
            printf("Empty queue.\n");
        }
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

void print_queue(queue q) {
    if (!(q.front == -1 && q.rear == -1)) {
        if (q.rear >= q.front) {
        for (int i = q.front; i <= q.rear; i++)
            printf("%d ",q.arr[i]);
        } else {
            for (int i = q.front; i < MAX; i++) {
                printf("%d ", q.arr[i]);
            }
            for (int i = 0; i <= q.rear; i++) {
                printf("%d ", q.arr[i]);
            }
        }
    }
    printf("\n");
}