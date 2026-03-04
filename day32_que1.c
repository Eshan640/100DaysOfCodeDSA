#include <stdio.h>

int main() {
    int n, m;
    
    // Read number of elements
    scanf("%d", &n);
    
    int stack[n];
    int top = -1;

    // Push elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    // Number of pops
    scanf("%d", &m);

    // Pop elements
    for(int i = 0; i < m; i++) {
        if(top >= 0) {
            top--;
        }
    }

    // Print remaining stack from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}