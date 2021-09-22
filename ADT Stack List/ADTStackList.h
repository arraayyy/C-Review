#ifndef ADTstaticListOperations
#define ADTstaticListOperations

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct{
    int elem[SIZE];
    int count;
}list, *ListPtr;

void initListV1(list * L){
    L->count = 0;
}

void selectionSortV1(list * L){
    int be, ce, lowest, temp;
    for(be = 0; be < L->count; be++){
        lowest = be;
        for(ce = be + 1; ce < L->count; ce++){
            if (L->elem[lowest] > L->elem[ce]){
                lowest = ce;
            }
        }
        temp = L->elem[ce];
        L->elem[ce] = L->elem[lowest];
        L->elem[lowest] = temp;
    }
}

void insertSortedV1(list * L, int elem){
    int x;

    if(L->count < SIZE){
        L->count++;
        for(x = L->count - 1; x > 0 && L->elem[x - 1] > elem; x--){
            L->elem[x] = L->elem[x - 1];
        }

        L->elem[x] = elem;
    }
}

void insertFirstV1(list *L, int elem){
    int x;

    if(L->count < SIZE){
        L->count++;
        for(x = L->count - 1; x > 0 ; x--){
            L->elem[x] = L->elem[x - 1];
        }

        L->elem[x] = elem;
    }
}

void insertLastV1(list *L, int elem){
    if(L->count < SIZE){
        L->count++;
        L->elem[L->count - 1] = elem;
    }
}

void deleteFirstV1(list * L){
    int x;
    
    L->count--;
    for(x = 0; x < L->count ; x++){
        L->elem[x] = L->elem[x + 1];
    }
}

void initListV2(ListPtr * L, list * n){
    *L = n; 
    (*L)->count = 0;
}

void selectionSortV2(ListPtr * L){
    int be, ce, lowest, temp;
    for(be = 0; be < (*L)->count; be++){
        lowest = be;
        for(ce = be + 1; ce < (*L)->count; ce++){
            if ((*L)->elem[lowest] > (*L)->elem[ce]){
                lowest = ce;
            }
        }
        temp = (*L)->elem[ce];
        (*L)->elem[ce] = (*L)->elem[lowest];
        (*L)->elem[lowest] = temp;
    }
}

void insertSortedV2(ListPtr * L, int elem){
    int x;

    if((*L)->count < SIZE){
        (*L)->count++;
        for(x = (*L)->count - 1; x > 0 && (*L)->elem[x - 1] > elem; x--){
            (*L)->elem[x] = (*L)->elem[x - 1];
        }

        (*L)->elem[x] = elem;
    }
}

void insertFirstV2(ListPtr *L, int elem){
    int x;

    if((*L)->count < SIZE){
        (*L)->count++;
        for(x = (*L)->count - 1; x > 0 ; x--){
            (*L)->elem[x] = (*L)->elem[x - 1];
        }

        (*L)->elem[x] = elem;
    }
}

void insertLastV2(ListPtr *L, int elem){
    if((*L)->count < SIZE){
        (*L)->count++;
        (*L)->elem[(*L)->count - 1] = elem;
    }
}

void deleteFirstV2(ListPtr * L){
    int x;
    
    (*L)->count--;
    for(x = 0; x < (*L)->count ; x++){
        (*L)->elem[x] = (*L)->elem[x + 1];
    }
}
#endif
