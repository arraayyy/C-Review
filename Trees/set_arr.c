#define MAX 100

typedef struct {
    int content[MAX];
    int count;
} SET;

/********** UNION **********/
SET Union (SET A, SET B) {
    SET c;
    int a, b;

    c.count = 0;
    a = b = 0;

    while(a < A.count && b < B.count) {
        if(A.content[a] < B.content[b]) {
            c.content[c.count] = A.content[a];
            a++;
        } else {
            if(A.content[a] == B.content[b]) {
                a++;
            }
            B.content[c.count] = B.content[b];
            b++;
        }
        c.count++;
    }

    if(b < B.count) {
        A = B;
        a = b;
    }

    while(a < A.count) {
        c.content[c.count] = A.content[a];
        a++;
        c.count++;
    } 
    return c;
}

/********** INTERSECTION **********/
SET intersection(SET A, SET B) {
    SET C;
    int a, b;
    C.count = 0;

    for(a = 0; a < A.count; a++) {
        for(b = 0; b < B.count && A.content[a] > B.content[b]; b++) {}

        if(b < B.count && A.content[a] == B.content[b]) {
            C.content[C.count] = A.content[a];
            C.count++;
        } 
    }

    return C;
}

/********** INSERT **********/
// Assuming all are unique

void insert(SET *S, int elem) {
    if(S->count < MAX) {
        S->content[S->count] = elem;
        ++S->count;
    }
}

// Assuming all elements to be inserted are unique, the best place to insert would be LAST

/********** DIFFERENCE **********/
SET difference(SET A, SET B) {
    SET C;
    int a, b;

    C.count = 0;

    for(a = 0; a < A.count; a++) {
        for(b = 0; b < B.count && A.content[a] > B.content[b]; b++) {}

        if(b == B.count || A.content[a] != B.content[b]) {
            C.content[C.count] = A.content[a];
            ++C.count;
        }
    }

    return C;
}

/********** MERGE **********/
SET merge(SET A, SET B) {
    SET C;

    C.count = 0;

    C = intersection(A, B);

    if(C.count == 0) {
        C = Union(A, B);
    } else {
        puts("Sets aren't disjoint");
        C.count = 0;
    }

    return C;
}



// !!! NOTE !!!
// functions being shown are based on a sorted scenario
// for unsorted
    // union - insert first all of SET A elements, then the insertLastUnique for SET B
    // difference && union - same code, but the relational operator will change