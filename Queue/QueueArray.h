#ifndef queueArray
#define queuearray

#include <stdio.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int front;
    int rear;
} Queue;

typedef enum {TRUE, FALSE} boolean;

void initialize(int front, Queue * Q){
    Q->front = front;
    Q->rear = (Q->front + 1) % MAX;
}

void enqueue(char elem, Queue * Q){
    if (!isFull(*Q)){
      Q->rear = (Q->rear + 1) % MAX;
      Q->elem[Q->rear] = elem;
    }
}

void dequeue(Queue * Q){
    if (!isEmpty(*Q)){
        Q->elem[Q->front] = -1;
        Q->front = (Q->front + 1) % MAX;
    }
}

char front(Queue Q){
    return Q.elem[Q.front];
}

char rear(Queue Q){
    return Q.elem[Q.rear];
}

boolean isFull(Queue Q){
    int front = (Q.front + 1) % MAX;
    int rear = (Q.rear + 1) % MAX;
    return front == rear + 1 ? TRUE : FALSE;
}

boolean isEmpty(Queue Q) {
    return Q.front >= (Q.rear + 1) % MAX ? TRUE : FALSE;
}
#endif
