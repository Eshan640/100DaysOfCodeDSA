 #include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        // Handle closing brackets
        else {
            if (top == -1) return false;  // No matching opening

            char last = stack[top--];

            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
        }
    }

    return top == -1;  // Stack must be empty
}