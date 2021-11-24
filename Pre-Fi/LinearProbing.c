#include <stdio.h>

#define EMPTY -1
#define DELETED - 2
#define MAX 8

typedef struct {
    char bits[MAX];
    int count;
} Dictionary;

void init(Dictionary *D) {
    int i;
    for (i = 0; i < MAX; i++)
        D->bits[i] = EMPTY;
    D->count = 0;
}

int hash(char elem) {
    int key = 0;

    int bit = sizeof(char) * 8 - 1;
    unsigned mask = 1 << bit; 

    while (mask > 0) {
        if (mask & elem) {
            key++;
        }
        mask >>= 1;
    }
    return key;
}

// Worst: O(N) Average: O(1) 
void insertV1(Dictionary *D, char bits) {
    int hash_val = hash(bits), trav, cnt;

    for (trav = hash_val, cnt = 0; 
            cnt < MAX && D->bits[trav] != bits && D->bits[trav] != EMPTY && D->bits[trav] != DELETED;
                cnt++, trav = (trav + 1) % MAX) {}
    if (cnt < MAX && D->bits[trav] != bits) {
        D->bits[trav] = bits;
    }
}

void insertV2(Dictionary *D, char bits) {
    int hash_val = hash(bits), trav, origVal;
    origVal = hash_val;

    if(D->bits[hash_val]==EMPTY || D->bits[hash_val]==DELETED){
        D->bits[hash_val] = bits;
    }else{
        for (trav = hash_val+1;
            trav!=origVal && D->bits[trav]!=bits && D->bits[trav]!=EMPTY && D->bits[trav]!=DELETED;
            trav = (trav + 1) % MAX) {
        }
        if(D->bits[trav]==EMPTY || D->bits[trav]==DELETED){
            D->bits[trav] = bits;
        }else{
            // full
        }
    }
}

// Worst: O(N) Average: O(1) 
void delete(Dictionary *D, char bits) {
    int hash_val = hash(bits), trav, cnt;

    for (trav = hash_val, cnt = 0; 
            cnt < MAX && D->bits[trav] != bits && D->bits[trav] != EMPTY;
                cnt++, trav = (trav + 1) % MAX) {}
    if (cnt < MAX && D->bits[trav] != EMPTY) {
        D->bits[trav] = DELETED;
    }
}

// Worst: O(N) Average: O(1) 
int isMember(Dictionary D, char bits) {
    int hash_val = hash(bits), trav, cnt;

    for (trav = hash_val, cnt = 0; 
            cnt < MAX && D.bits[trav] != bits && D.bits[trav] != EMPTY;
                cnt++, trav = (trav + 1) % MAX) {}

    return (cnt < MAX && D.bits[trav] != EMPTY)? 1:0;
}

void display(Dictionary D) {
    int i;

    for (i = 0; i < MAX; i++) {
        printf("%d: ", i);
        int bit = sizeof(char) * 8 - 1;
        unsigned mask = 1 << bit; 

        while (mask > 0) {
            if (mask & D.bits[i]) {
                printf("1");
            }
            else {
                printf("0");
            }
            mask >>= 1;
        }
        printf("\n");
    }
}

int main () {
    Dictionary D;
    init (&D);
    insertV1(&D, 7);
    insertV1(&D, 1);
    insertV1(&D, 3);
    insertV1(&D, 2);
    insertV1(&D, 55);
    insertV1(&D, 56);
    insertV1(&D, 5);
    insertV1(&D, 11);
    insertV1(&D, 67);
    insertV1(&D, 68);

    // delete (&D, 11);
    display(D);

    printf("\n\nIs Member: %d", isMember(D,5));

    return 0;
}
