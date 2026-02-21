#include <stdio.h>
#include <stdlib.h>

// Define structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read first value
    scanf("%d", &value);
    head = createNode(value);
    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        temp->next = newNode;
        temp = newNode;
    }

    // Traverse and print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}