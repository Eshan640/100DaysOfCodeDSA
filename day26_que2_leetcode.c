#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;


/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

/** Add a node of value val before the first element of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    obj->size++;
}

/** Add a node of value val before the index-th node in the linked list. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;

    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    obj->size--;
}

/** Free all nodes */
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */