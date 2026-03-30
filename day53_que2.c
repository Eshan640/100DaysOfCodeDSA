#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue Node (for BFS)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue structure
struct Queue {
    int front, rear, size;
    struct QNode* array;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = size;
    q->array = (struct QNode*)malloc(size * sizeof(struct QNode));
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->array[q->rear].node = node;
    q->array[q->rear].hd = hd;
    q->rear++;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    return q->array[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map HD range (assuming -100 to +100)
    int map[201][100]; // store nodes
    int count[201] = {0};

    int offset = 100; // to handle negative HD

    struct Queue* q = createQueue(1000);
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
            enqueue(q, node->left, hd - 1);

        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    // Print vertical order
    for (int i = 0; i < 201; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Example usage
int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}