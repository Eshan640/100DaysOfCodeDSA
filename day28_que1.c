#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Create first node
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;

    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Make it circular
    temp->next = head;

    // Traverse and print circular linked list
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    return 0;
}