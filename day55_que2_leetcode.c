/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Simple queue implementation
struct Queue {
    struct TreeNode **data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    int capacity = 1000;
    int* result = (int*)malloc(capacity * sizeof(int));

    struct Queue* q = createQueue(capacity);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            // last node of this level
            if (i == levelSize - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }

    return result;
}