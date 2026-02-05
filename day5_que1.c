#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int A[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int B[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    // Print remaining elements of A
    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    // Print remaining elements of B
    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
