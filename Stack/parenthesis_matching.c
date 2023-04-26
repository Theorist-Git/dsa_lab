#include <stdio.h>
#include "stack_struct.c"

int is_balanced(char* arr) {
    int i = 0;
    stack stk;
    stk.top = -1;

    while (*(arr + i) != '\0') {
        char character = *(arr + i);
        if(character == '(' || character == '{' || character == '[') {
            push(&stk, character);
        } else if (character == ')' || character == '}' || character == ']') {
            if (
                is_empty(&stk)
                ||
                !(character == stk.stack[stk.top] + 1 || character == stk.stack[stk.top] + 2)
            ) {
                return 0;
            } else {
                pop(&stk);
            }
        }
        i++;
    }

    return 1;
}

int main() {
    char arr[MAX];
    printf("Enter expression: ");
    fgets(arr, MAX, stdin);

    printf("%d", is_balanced(arr));

    return 0;
}