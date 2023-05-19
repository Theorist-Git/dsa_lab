#include <stdio.h>
#include "queue_struct.c"

int main() {
    queue q;
    q.front = -1;
    q.rear = -1;

    while (1) {
        int choice;
        printf("Enter 1 to ENQUEUE\nEnter 2 to DEQUEUE\nEnter 0 to QUIT: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int val;
            printf("Enter value to be PUSHED: ");
            scanf("%d", &val);
            enqueue(&q, val);
            printf("Front: %d\n", q.front);
            printf("Rear: %d\n", q.rear);
            print_queue(q);
        } else if (choice == 2) {
            dequeue(&q);
            printf("Front: %d\n", q.front);
            printf("Rear: %d\n", q.rear);
            print_queue(q);
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}