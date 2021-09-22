#ifndef stackList
#define stackList

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    char elem;
    struct cell *next;
}node;

typedef struct stackList {
    node * top;
}Stack;


void initialize(Stack * S){
    S->top = NULL;
}

int isEmpty(Stack S){
    return S.top == NULL ? 1:0;
}

void push(Stack * S, char c){
    node * newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->elem = c;
    if(S->top != NULL){ newNode->next = S->top; } else { newNode->next = NULL; }
    S->top = newNode;
}

void pop(Stack * S){
    node * temp;
    temp = S->top;
    S->top = temp->next;
    free(temp);
}

int top(Stack S){
    return S.top->elem;
}
#endif
