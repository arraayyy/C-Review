#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 5
#define MAX_EDGES 10

typedef struct {
    int vertex;
    int adj_vertex;
} EdgeType;

typedef struct {
    EdgeType edges[MAX_EDGES];
    int count;
} EdgeList;

typedef int **MATRIX;  // matrix 1
// typedef int MATRIX[MAX_VERTEX][MAX_VERTEX]; // matrix 2

void initMatrixV1(MATRIX *M) {
    *M = (MATRIX)calloc(sizeof(int *), MAX_VERTEX);

    for (int i = 0; i < MAX_VERTEX; i++) {
        (*M)[i] = (int *)calloc(sizeof(int), MAX_VERTEX);
    }
}

void initMatrixV2(MATRIX M) {
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            M[i][j] = 0;
        }
    }
}

void insertMatrix(MATRIX M, int vx, int vy) {
    if (vx >= 0 && vx < MAX_VERTEX && vy >= 0 && vy < MAX_VERTEX) {
        M[vx][vy] = 1;
    }
}

void populateMatrix(MATRIX M, EdgeList E) {
    if (M && E.count >= 0 && E.count <= MAX_EDGES) {
        for (int i = 0; i < E.count; i++) {
            insertMatrix(M, E.edges[i].vertex, E.edges[i].adj_vertex);
            insertMatrix(M, E.edges[i].adj_vertex, E.edges[i].vertex);
        }
    }
}

void displayV1(MATRIX M) {
    int i, j;
    printf("   ");
    for (i = 0; i < MAX_VERTEX; i++) printf("%d ", i);

    for (i = 0; i < MAX_VERTEX; i++) {
        printf("\n%d: ", i);
        for (j = 0; j < MAX_VERTEX; j++) {
            printf("%d ", M[i][j]);
        }
    }
}

int main() {
    EdgeList E = {{{1, 3}, {2, 3}, {3, 4}, {0, 1}, {3, 0}}, 5};
    MATRIX M;
    initMatrixV1(&M);  // matrix 1
    // initMatrixV2(M); // matrix 2
    populateMatrix(M, E);
    displayV1(M);

    return 0;
}
