#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 1000
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        exit(1);
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        exit(1);
    }
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL) {
        int len = strlen(token);
        if (len > 0 && token[len - 1] == '.') {
            token[len - 1] = '\0';
            len--;
        }

        if (len > 0) {
            if (isdigit(token[0])) {
                int num = atoi(token);
                push(num);
            } else {
                int b = pop();
                int a = pop();
                if (strcmp(token, "+") == 0) {
                    push(a + b);
                } else if (strcmp(token, "-") == 0) {
                    push(a - b);
                } else if (strcmp(token, "*") == 0 || strcmp(token, "\xC3\x97") == 0) {
                    push(a * b);
                } else if (strcmp(token, "/") == 0) {
                    if (b == 0) {
                        exit(1);
                    }
                    push(a / b);
                } else {
                    exit(1);
                }
            }
        }
        token = strtok(NULL, " ");
    }

    if (top != 0) {
        exit(1);
    }

    int result = pop();
    printf("%d\n", result);
    return 0;
}
