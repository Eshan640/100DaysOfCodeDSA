#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);

        if (strcmp(operation, "ENQUEUE") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (strcmp(operation, "DEQUEUE") == 0) {
            dequeue();
        }
    }

    return 0;
}