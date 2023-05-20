#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct.c"

int precedence(char operator)
{
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* infix_to_prefix(char* infix) {

    int i = 0, j = 0;
    int len = strlen(infix);
    int proper_len = 0;
    for (int k = 0; k < len; k++) {
        if (*(infix + k) != '(' && *(infix + k) != ')') {
            proper_len++;
        }
    }
    
    char* postfix = (char*)calloc(sizeof(char), proper_len + 1);
    char* infix_rev = (char*)calloc(sizeof(char), len);

    for (int k = len - 1, l = 0; k >= 0; k--) {
        char inf_char = *(infix + k);
        if (inf_char == '(') {
            infix_rev[l] = ')';
            l++;
        } else if (inf_char == ')') {
            infix_rev[l] = '(';
            l++;
        } else {
            infix_rev[l] = inf_char;
            l++;
        }
    }

    stack stk;
    stk.top = -1;

    while (*(infix_rev + i) != '\0') {
        char character = *(infix_rev + i);

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
            postfix[j++] = character;
            
        } else if (character == '(') {
            push(&stk, character);
        } else if (character == ')') {
            while (stk.top > -1 && stk.stack[stk.top] != '(') {
                postfix[j++] = stk.stack[stk.top];
                pop(&stk);
            }
            pop(&stk);
        } else if (isOperator(character)) {
            if (isOperator(stk.stack[stk.top])) {
                if (precedence(character) > precedence(stk.stack[stk.top])) {
                    push(&stk, character);
                } else {
                    while (
                        precedence(character) < precedence(stk.stack[stk.top])
                        && 
                        isOperator(character)
                        &&
                        stk.top > -1
                    ) {
                        postfix[j++] = stk.stack[stk.top];
                        pop(&stk);
                    }
                    push(&stk, character);
                }
                
            } else {
                push(&stk, character);
            }
        }
        i++;
    }

    while (stk.top > -1) {
        postfix[j++] = stk.stack[stk.top];
        pop(&stk);
    }
    
    return strrev(postfix);
}

int main() {
    char infix[] = "x+y*z/w+u";
    char* prefix = infix_to_prefix(infix);

    printf("%s\n", prefix);
    free(prefix);
    
    return 0;
}