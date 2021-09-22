#ifndef queueList
#define queueList

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node * next;
} node;

typedef enum {TRUE, FALSE} boolean;

typedef struct {
	node * front;
	node * rear;
} Queue;

void initialize(Queue * Q){
	Q->front = NULL;
	Q->rear = NULL;	
}

char front(Queue Q){
	return Q.front->elem;
}

char rear(Queue Q){
	return Q.rear->elem;
}

boolean isEmpty(Queue Q){
	return Q.front == NULL ? TRUE:FALSE;
}

void enqueue(Queue* Q, char c){
	node * temp;
	temp = (node*) malloc(sizeof(node));
	temp->elem = c;
	temp->next = NULL;

	if(Q->rear != NULL) { Q->rear->next = temp; }
	Q->rear = temp;

	if(Q->front == NULL){
		Q->front = temp;
	}
}

void dequeue(Queue * Q){
	node * temp;
	if(Q->front != NULL){
        temp = Q->front;
        Q->front = temp->next;
        free(temp);
		
		if(Q->front == NULL){
			Q->rear = Q->front;
		}
    }
}
#endif
