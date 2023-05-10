#include <stdio.h>
#include "C:\Users\mayan\Desktop\languages\C\Lab_sem_2\Stack\stack_struct.c"

typedef struct Queue {
    stack stk1, stk2;
} queue;

void enqueue(queue* q, int val) {
    push(&(q->stk1), val);
}

void dequeue(queue* q) {
    int val;

    if (is_empty(&q->stk1) && is_empty(&q->stk2)) {
        return;
    } else if (is_empty(&q->stk2)) {
        while (!is_empty(&q->stk1)) {
            val = q->stk1.stack[q->stk1.top];
            pop(&q->stk1);
            push(&q->stk2, val);
        }
        pop(&(q->stk2));
        while (!is_empty(&q->stk2)) {
            val = q->stk2.stack[q->stk2.top];
            pop(&q->stk2);
            push(&q->stk1, val);
        }
    }
}

int is_queue_full(queue* q) {
    return is_full(&q->stk1);
}

int is_queue_empty(queue* q) {
    return is_empty(&q->stk1);
}

int main() {
    queue q;
    q.stk1.top = -1;
    q.stk2.top = -1;
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    dequeue(&q);
    enqueue(&q, 100);
    enqueue(&q, 800);
    dequeue(&q);
}