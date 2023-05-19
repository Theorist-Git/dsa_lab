#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int stack[MAX];
    int top;
} stack;

int is_full(stack* stk) {
    if (stk->top == MAX - 1) {
        return 1;
    }
    return 0;
}

int is_empty(stack* stk) {
    if (stk->top == -1) {
        return 1;
    }
    return 0;
}


void print_stack(stack* stk) {
    for (int i = 0; i <= stk->top; i++) {
        printf("%d ", stk->stack[i]);
    }
    printf("\n");
}

void push(stack* stk, int val) {
    if (stk->top < MAX - 1) {
        stk->top++;
        stk->stack[stk->top] = val;
    } else {
        printf("Stack Overflow\nMax stack size: %d\n", MAX);
    }
}

void pop(stack* stk) {
    if (stk->top != -1) {
        stk->top--;
    } else {
        printf("Stack Underflow\n");
    }
}

void seek(stack* stk) {
    if (stk->top != -1) {
        printf("Last Element i.e top points to: %d\n", stk->stack[stk->top]);
    } else {
        printf("Stack is empty\n");
    }
}