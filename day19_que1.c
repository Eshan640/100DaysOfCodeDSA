#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x - y);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least two elements\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int first = arr[left], second = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d\n", first, second);

    return 0;
}
