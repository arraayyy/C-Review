#define MAX 45

typedef struct {
    int elem;
    int link;
} stype, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int Avail;
} VHeap;

typedef int SET;

/********** UNION **********/
SET Union(SET A, SET B, VHeap *VH) {
    SET C, *trav;

    C = -1; 
    trav = &C;

    while(A != -1 && B != -1) {
        *trav = VH->Avail;
        if(*trav != -1) {
            VH->Avail = VH->H[*trav].link;
            if(VH->H[A].elem = VH->H[B].elem) {
                VH->H[*trav].elem = VH->H[A].elem;
                A = VH->H[A].link;
            } else {
                if(VH->H[A].elem = VH->H[B].elem) {
                    A = VH->H[A].link;
                }
                VH->H[*trav].elem = VH->H[B].elem;
                B = VH->H[B].link;
            }
            trav = &VH->H[*trav].link;
        }
    }
    if(A == -1 && B != -1) {
        A = B;
    }

    while(A != -1) {
        *trav = VH->Avail;

        if(*trav != -1) {
            VH->Avail = VH->H[*trav].link;
            VH->H[*trav].elem = VH->H[A].elem;
            trav = &VH->H[*trav].link;
            A = VH->H[A].link;
        }
    }

    *trav = -1;

    return C;
}

/********** INTERSECTION **********/
SET intersection(SET A, SET B, VHeap *VH) {
    SET C, travB, *trav;

    C = -1;
    trav = &C;

    for(; A != -1; A = VH->H[A].link) {
        for(travB = B; travB != -1 && VH->H[A].elem > VH->H[travB].elem; travB = VH->H[travB].link) {}

        if(travB != -1 && VH->H[A].elem == VH->H[travB].elem) {
            *trav = VH->Avail;
            
            if(*trav != -1) {
                VH->Avail = VH->H[*trav].link;
                VH->H[*trav].elem = VH->H[A].elem;
                trav = &VH->H[*trav].link;
            }
        }   
    }

    *trav = -1;

    return C;
}

/********** INSERT **********/

void insert(SET *S, int pos, int elem, VHeap *VH) {
    SET *trav, temp;
    int curPos = 0;

    if(pos < MAX) {
        for(trav = S; *trav != -1 && curPos < pos; trav = &VH->H[*trav].link) {}

        if(curPos == pos) {
            temp = VH->Avail;

            if(temp != -1) {
                VH->Avail = VH->H[temp].link;
                VH->H[temp].link = *trav;
                *trav = temp;
            }
        }
    }
}

/********** DIFFERENCE **********/
SET difference(SET A, SET B, VHeap *VH) {
    SET *trav, C, travB;

    C = -1;
    trav = &C;

    for(; A != -1; A = VH->H[A].link) {
        for(travB = B; travB != -1 && VH->H[travB].elem < VH->H[A].elem; travB = VH->H[travB].link) {}

        if(travB == -1 || VH->H[travB].elem != VH->H[A].elem) {
            *trav = VH->Avail;

            if(*trav != -1) {
                VH->Avail = VH->H[*trav].link;
                VH->H[*trav].elem = VH->H[A].elem;
                trav = &VH->H[*trav].link;
            }
        }
    }

    *trav = -1;

    return C;
}

/********** MERGE **********/
SET merge(SET A, SET B, VHeap *VH) {
    SET C;

    C = -1;
    C = intersection(A, B, VH);

    if(C == -1) {
        C = Union(A, B, VH);
    } else {
        puts("Sets aren't disjoint");
        C = -1;
    }

    return C;
}