#define NULL 0

typedef struct node {
    int data;
    struct node *next;
} dtype, *SET;

/********** UNION **********/
SET Union (SET A, SET B) {
    SET C, *trav;
    C = NULL; 
    trav = &C;

    while(A != NULL && B != NULL) {
        *trav = (SET)malloc(sizeof(dtype));
        if(*trav != NULL) {
            if(A->data < B->data) {
                (*trav)->data = A->data;
                A = A->next;
            } else {
                if(A->data == B->data) {
                    A = A->next;
                }
                (*trav)->data = B->data;
                B = B->next;
            }
            trav = &(*trav)->next;
        }
    }

    if(A == NULL && B != NULL) {
        A = B;
    }

    while(A != NULL) {
        (*trav) = (SET)malloc(sizeof(dtype));

        if(*trav != NULL) {
            (*trav)->data = A->data;
            trav = &(*trav)->next;
            A = A->next;
        }
    }
    return C;
}

/********** INTERSECTION **********/
SET intersection(SET A, SET B) {
    SET *trav, C, temp;
    
    C = NULL;
    trav = &C;

    for(; A != NULL; A = A->next) {
        for(temp = B; temp != NULL && A->data > temp->data; temp = temp->next) {}

        if(temp != NULL && A->data == temp->data) {
            *trav = (SET)malloc(sizeof(dtype));
            if(*trav != NULL) {
                (*trav)->data = A->data;
                trav = &(*trav)->next;
            }
        }
    }

    *trav = NULL;

    return C;
}

/********** INSERT **********/
// insert at a given position

void insert(SET *S, int pos, int data) {
    SET *trav, temp;
    int curPos = 0;

    for(trav = S; *trav != NULL && curPos < pos; trav = &(*trav)->next, curPos++) {}

    if(curPos == pos) {
        temp = (SET)malloc(sizeof(dtype));

        if(temp != NULL) {
            temp->data = data;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

// though assuming all elements to be inserted are unique, the best place to insert would be FIRST

/********** DIFFERENCE **********/
SET difference(SET A, SET B) {
    SET C, temp, *trav;

    C = NULL;
    trav = &C;

    for(; A != NULL; A = A->next) {
        for(temp = B; temp != NULL && A->data > temp->data; temp = temp->next) {}

        if(temp == NULL || A->data != temp->data) {
            *trav = (SET)malloc(sizeof(dtype));
            
            if(*trav != NULL) {
                (*trav)->data = A->data;
                trav = &(*trav)->next;
            }
        }
    }

    *trav = NULL;

    return C;

 /********** MERGE **********/
SET merge(SET A, SET B) {
    SET C;

    C = NULL;
    C = intersection(A, B);

    if(C == NULL) {
        C = Union(A, B);
    } else {
        puts("Sets aren't disjoint");
        C = NULL;
    }

    return C;
}

/********** MIN **********/
int MIN(SET S) {
    int MIN = 1000;
    SET trav;

    for(trav = S; trav != NULL; trav = trav->next) {
        if(trav->data < MIN) {
            MIN = trav->data;
        }
    }

    return MIN;
}

/********** MAX **********/
int MAX(SET S) {
    int MAX = 0;
    SET trav;

    for(trav = S; trav != NULL; trav = trav->next) {
        if(trav->data > MAX) {
            MAX = trav->data;
        }
    }

    return MAX; // 0????
}