#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

/** Move elements if stack2 is empty */
void transfer(MyQueue* obj){
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}