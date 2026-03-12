#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % size == front) {
        return; // queue full (won't happen in this problem)
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

// Dequeue operation
int dequeue() {
    if (front == -1) {
        return -1; // empty
    }

    int value = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return value;
}

// Print queue from front to rear
void printQueue() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    size = n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // Perform circular dequeues
    for (int i = 0; i < m; i++) {
        int val = dequeue();
        enqueue(val);
    }

    printQueue();

    return 0;
}