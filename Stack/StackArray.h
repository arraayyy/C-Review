#ifndef stackArray
#define stackArray

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
}Stack;

typedef enum {TRUE, FALSE} boolean;

/* ADT STACK VERSION 1 */
void initialize(Stack * S){
    S->top = MAX;
}

boolean isEmpty(Stack S){
    return S.top == MAX ? TRUE:FALSE;
}

boolean isFull(Stack S){
    return S.top == 0 ? TRUE:FALSE;
}

char top(Stack S){
    return S.elem[S.top];
}

void push(Stack *S, char c){
    if(!isFull(*S)){
        S->top--;
        S->elem[S->top] = c;
    }
}

void pop(Stack *S){
    if(!isEmpty(*S)){
        S->top++;
    }
}

void display(Stack *S){
	Stack temp;
	initialize(&temp);

	while(!isEmpty(*S)){
		printf("%c ", top(*S));
		push(&temp, top(*S));
		pop(S);
	}

	while(!isEmpty(temp)){
		push(&temp, top(temp));
		pop(&temp);
	}
}

/* ADT STACK VERSION 2

void initialize(Stack * S){
    S->top = -1;
}

int isEmpty(Stack S){
    return S.top == -1 ? 1:0;
}

int isFull(Stack S){
    return S.top+1 == MAX - 1 ? 1:0;
}

char top(Stack S){
    return S.elem[S.top];
}

void push(char c, Stack * S){
    if(isFull(*S) == 0){
        S->top++;
        S->elem[S->top] = c;
    }
}

void pop(Stack * S){
    if(isEmpty(*S) == 0){
        S->top--;
    }
}

void displayStack(Stack S){
    Stack *temp;
    temp = (Stack*) malloc(sizeof(Stack));
    const int t = S.top + 1;

    for(temp = 0; temp->top < t; temp->top++){
        temp->elem[temp->top] = S.elem[temp->top];
        printf("\nElem[%d]: %c", temp->top, temp->elem[temp->top]);
    }
    free(temp);
}
*/

/* inserBottom() */
void insertBottom(char c, Stack * S){
    if(isEmpty(*S) == 1){
        push(S, c);
    } else {
        if(isFull(*S) == 1) { pop(S); }
        push(S, c);
    }
}
#endif
