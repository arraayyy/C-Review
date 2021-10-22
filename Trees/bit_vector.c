#define SIZE 8
#define NULL 0

typedef int BitVector[SIZE];
typedef int SET[SIZE];

/********** UNION **********/
SET *Union(SET A, SET B) {
    SET *C;

    C = NULL;
    
    int i;

    C = (SET *)calloc(1, sizeof(SET));

    if(C != NULL) {
        for(i = 0; i < SIZE; i++) {
            (*C)[i] = A[i] | B[i];
        }
    }

    return C;
}

/********** INTERSECTION **********/
SET *intersection(SET A, SET B) {
    SET *C;
    int i;
    C = NULL;

    C = (SET *)malloc(sizeof(SET));

    if(C != NULL) {
        for(i = 0; i < SIZE; i++) {
            (*C)[i] = A[i] & B[i]; 
        }
    }

    return C;
}

/********** DIFFERENCE **********/
SET* difference(SET A, SET B) {
    SET * C;
    int i;

    C = (SET *)malloc(sizeof(SET));

    if(C != NULL) {
        for(i = 0; i < SIZE; i++) {
            (*C)[i] = A[i] & ~B[i];
        }
    }

    return C;
}

/********** INSERT **********/
void insert(SET S, int pos) {
    if(pos <  SIZE) {
        S[pos] |= 1;
    }
}

/********** DELETE **********/
void delete(SET S, int pos) {
    if(pos < SIZE) {
        S[pos] &= 0;
    }
}