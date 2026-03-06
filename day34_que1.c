#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack top
struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {

    for (int i = 0; exp[i] != '\0'; i++) {

        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If operand push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else {

            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }

    return pop();
}

int main() {

    char exp[] = "2 3 1 * + 9 -";

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}