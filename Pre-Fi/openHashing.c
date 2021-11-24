#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 26
/*
Case-Insensitive
0  -> A 
1  -> B
2  -> C
3  -> D
4  -> E
5  -> F
6  -> G
7  -> H
8  -> I
9  -> J
    ...

    
Algorithm	Average	    Worst case
Space		O(n)[1]	    O(n)
Search		O(1)	    O(n)
Insert		O(1)	    O(n)
Delete		O(1)	    O(n)
*/

typedef struct node {
    char name[40];      // 40 bytes
    struct node* next;
} *NodePtr;          // 8 bytes

typedef NodePtr Dictionary[MAX];

int hash (char name[]) {
    return toupper(name[0]) - 65; 
}

// Average: O(1) 
void insertFront(Dictionary D, char name[]) {
    NodePtr temp;
    int hash_val = hash(name);

    temp = (NodePtr)malloc(sizeof(struct node));
    if (temp != NULL) {
        strcpy(temp->name, name);
        temp->next = D[hash_val];
        D[hash_val] = temp;
    }
}

// Worst Case: O(N) Best Case: O(1)
void insertRear(Dictionary D, char name[]) {
    NodePtr *trav;
    int hash_val = hash(name);

    for (trav = &D[hash_val]; *trav != NULL && strcmp((*trav)->name, name) != 0; trav = &(*trav)->next) {} 
    if (*trav == NULL) {
        *trav = (NodePtr)malloc(sizeof(struct node));
        if (*trav != NULL) {
            strcpy((*trav)->name, name);
            (*trav)->next = NULL;
        }
    }
}

// Worst Case: O(N) Best Case: O(1) Average: O(log n)
void delete(Dictionary D, char name[]) {
    NodePtr *trav, temp;
    int hash_val = hash(name);

    for (trav = &D[hash_val]; *trav != NULL && strcmp((*trav)->name, name) != 0; trav = &(*trav)->next) {}
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

// Worst Case: O(N) Best Case: O(1) Average: O(log n)
int isMember(Dictionary D, char name[]) {
    NodePtr trav;
    int hash_val = hash(name);   

    for (trav = D[hash_val]; trav != NULL && strcmp(trav->name, name) != 0; trav = trav->next) {} 

    return (trav != NULL)? 1:0;
}

void populate(Dictionary D, char *list[], int size) {
    int i;

    for (i = 0 ; i < size ; i++)
        insertRear(D, list[i]);
}

void display(Dictionary D) {
    int i;
    NodePtr trav;

    for (i = 0; i < MAX; i++) {
        printf("%d: ", i);
        for (trav = D[i]; trav != NULL; trav = trav->next) {
            printf("%-10s", trav->name);
        }
        printf("\n");
    }
}

int main () {
    Dictionary D = {}; 
    char *list[]={"Edwin", "Horeb", "Francia", "Nina", "Roque"};

    populate(D, list, sizeof(list)/sizeof(list[0]));
    delete(D, "Horeb");
    delete(D, "Edwin");

    display(D);
    printf("\n\nIs Member? %d", isMember(D, "Francia"));

    return 0;
}
