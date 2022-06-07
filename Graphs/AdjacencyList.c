#include <stdio.h>
#include <stdlib.h>

#define VMAX 5 // max vertices
#define EMAX 10  // max edges; n(n-1)/2

// EdgeType = contains x and y vertices
// EdgeList = list of EdgeTypes
// Node, *NodePtr = node for vertex
// AdjList = list of vertices

typedef struct {
    int vertex;
    int adj_vertex;
} EdgeType;

typedef struct {
    EdgeType edges[EMAX];
    int count;
} EdgeList;

typedef struct node {
    int vertex;
    struct node *next;
} Node, *NodePtr;

typedef NodePtr AdjList[VMAX];

// init AdjList
// insert first
// insert last
// populate AdjList

void initAdjList(AdjList A) {
    for (int i = 0; i < VMAX; i++) {
        A[i] = NULL;
    }
}

void insertFirst(AdjList A, int vx, int vy) {
    NodePtr *trav, temp;
    if (vx <= VMAX && vy <= VMAX && vx >= 0 && vy >= 0) {
        trav = &A[vx];
        temp = (NodePtr)calloc(sizeof(Node), 1);
        if (temp) {
            temp->vertex = vy;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void insertLast(AdjList A, int vx, int vy) {
    NodePtr *trav;
    if (vx <= VMAX && vy <= VMAX && vx >= 0 && vy >= 0) {
        for (trav = &A[vx]; *trav != NULL; trav = &(*trav)->next) {
        }
        *trav = (NodePtr)calloc(sizeof(Node), 1);
        if (*trav) {
            (*trav)->vertex = vy;
        }
    }
}

void populateAdjList(AdjList A, EdgeList E) {
    if (A && E.count > 0) {
        for (int i = 0; i < E.count; i++) {
            insertFirst(A, E.edges[i].vertex, E.edges[i].adj_vertex);
            insertFirst(A, E.edges[i].adj_vertex, E.edges[i].vertex);
            // insertLast(A, E.edges[i].vertex, E.edges[i].adj_vertex);
            // insertLast(A, E.edges[i].adj_vertex, E.edges[i].vertex);
        }
    }
}

void displayAdjList(AdjList A) {
    for (int i = 0; i < VMAX; i++) {
        printf("%d: ", i);
        for (NodePtr trav = A[i]; trav != NULL; trav = trav->next) {
            printf("%d ", trav->vertex);
        }
        printf("\n");
    }
}

int main() {
    EdgeList E = {{{1, 2}, {1, 3}, {2, 3}, {3, 4}}, 4};
    AdjList A;

    initAdjList(A);
    populateAdjList(A, E);
    displayAdjList(A);

    return 0;
}
