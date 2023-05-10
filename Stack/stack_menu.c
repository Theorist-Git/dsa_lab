#include <stdio.h>
#include "stack_struct.c"

int main() {
    stack stk;
    stk.top = -1;

    while (1) {
        int choice;
        printf("Enter 1 to PUSH to stack\nEnter 2 to POP stack\nEnter 3 to SEEK\nEnter 0 to QUIT: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int val;
            printf("Enter value to be PUSHED: ");
            scanf("%d", &val);
            push(&stk, val);
        } else if (choice == 2) {
            pop(&stk);
        } else if (choice == 3) {
            seek(&stk);
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}