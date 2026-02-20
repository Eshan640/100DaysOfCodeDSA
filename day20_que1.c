#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Simple hash map implementation using arrays
typedef struct {
    long long key;
    int count;
} Hash;

Hash hashTable[MAX];
int hashSize = 0;

// Function to find key in hash table
int find(long long key) {
    for (int i = 0; i < hashSize; i++) {
        if (hashTable[i].key == key)
            return i;
    }
    return -1;
}

// Function to insert/update key in hash table
void insert(long long key) {
    int idx = find(key);
    if (idx != -1) {
        hashTable[idx].count++;
    } else {
        hashTable[hashSize].key = key;
        hashTable[hashSize].count = 1;
        hashSize++;
    }
}

int getCount(long long key) {
    int idx = find(key);
    if (idx != -1)
        return hashTable[idx].count;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long prefixSum = 0;
    long long result = 0;

    // Insert prefix sum 0 initially
    insert(0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefixSum seen before, add its frequency
        result += getCount(prefixSum);

        // Insert/update prefixSum in hash table
        insert(prefixSum);
    }

    printf("%lld\n", result);

    return 0;
}