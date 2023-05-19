#include <stdio.h>
#include "stack_struct.c"

void input_array(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        int num;
        printf("Enter element for index %d\n", i);
        scanf("%d", &num);
        arr[i] = num;
    }
}


int main() {
    int arr[10];
    int len = 10;
    input_array(arr, len);
    
    stack stk;
    stk.top = -1;

    for (int i = 0; i < len; i++) {
        push(&stk, arr[len - (i + 1)]);
    }
    print_stack(&stk);

    return 0;
}