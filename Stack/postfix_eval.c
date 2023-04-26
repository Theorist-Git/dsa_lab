#include <stdio.h>
#include <ctype.h>
#include "stack_struct.c"

int postfix_eval(char* postfix) {
    int i = 0;
    stack stk;
    stk.top = -1;

    while (*(postfix + i) != '\0') {

        if (isdigit(*(postfix + i))) {
            push(&stk, *(postfix + i) - '0');
        } else {
            int eval;
            char character = *(postfix + i);
            if (character == '+') {
                eval =  stk.stack[stk.top - 1] + stk.stack[stk.top];
                pop(&stk); pop(&stk);
                push(&stk, eval);
            } else if (character == '-') {
                eval =  stk.stack[stk.top - 1] - stk.stack[stk.top];
                pop(&stk); pop(&stk);
                push(&stk, eval);
            } else if (character == '*') {
                eval =  stk.stack[stk.top] * stk.stack[stk.top - 1];
                pop(&stk); pop(&stk);
                push(&stk, eval);
            } else if (character == '^') {
                eval =  stk.stack[stk.top] ^ stk.stack[stk.top - 1];
                pop(&stk); pop(&stk);
                push(&stk, eval);
            } else if (character == '/') {
                eval =  stk.stack[stk.top - 1] / stk.stack[stk.top];
                pop(&stk); pop(&stk);
                push(&stk, eval);
            }
        }
        i++;
    }

    int evaluation = stk.stack[stk.top];
    pop(&stk);

    return evaluation;
}

int main() {
    char exp[] = "231*+9-";

    printf("postfix evaluation: %d", postfix_eval(exp));
    
    return 0;
}