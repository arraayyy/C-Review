#define NULL 0

typedef char SET;

/********** UNION **********/
SET Union(SET A, SET B) {
    return A | B;
}

/********** INTERSECTION **********/
SET intersection(SET A, SET B) {
    return A & B;
}

/********** DIFFERENCE **********/
SET difference(SET A, SET B) {
    return A & ~B;
}

/********** INSERT **********/
void insert(SET *S, int pov) {
    if(pov <= (sizeof(*S) *8)) {
        *S = *S | (1 << pov);
    }
}

/********** DELETE **********/
void delete(SET *A, int i) {
    if(i <= (sizeof(*A) * 8)) {
        *A = (*A) & ~ (1 << i);
    }
}

/**********  **********/
SET* setToBitVector(CompWord Val) {
    SET* S;
    int bit, i;
    unsigned int max;

    bit = (sizeof(val) << 3) - 1; // highest exponent or power within val
    S = NULL;
    S = (SET*)malloc(sizeof(SET));

    if(S != NULL) {
        max = 1 << bit;

        for(i = SIZE - 1; i >= 0; i--, max >>= 1) {
            (*S)[i] = (val & max)? 1 : 0;
        }
    }

    return S;
}

/********** **********/
int numOfBit(CompWord val) {
    int sum, bit;
    unsigned int max;

    bit = (sizeof(val) << 3) - 1;

    for(sum = 0; max = 1 << bit; max > 0; max >>= 1) {
        sum += (val & max) ? 1 : 0;
    }

    return sum;
}