#include <stdio.h>
#define MAX 20

typedef struct {
    char fname[16];
    char lname[16];
    char mi;
}NameType;

typedef struct {
    int id;
    NameType name;
    int age;
    char course[8];
    int yr;
}StudType;

typedef struct {
    StudType stud[MAX];
    int last;
}POT;

void init(POT *P);
void populate(POT *P, StudType arr[], int size);
void insert(POT *P, StudType data);   // just insert
void insertV1(POT *P, StudType data); // via swapping then Bubble up
void insertV2(POT *P, StudType data); // via shifting then Bubble up
StudType deleteMinV1(POT *P); // via swapping then sink
StudType deleteMinV2(POT *P); // via shifting then sink
void display(POT P);
void displayStudent(StudType stud);
void heapSort(POT *P);
void minHeapify(POT *P);
void displayHeader();

int main () {
    POT P;
    init(&P);
    StudType studArr[] = {
            {7,{"AAA", "AAAAA", 'A'},20,"BSCS",2},
            {5,{"BBB", "BBBBB", 'B'},21,"BSCS",1},
            {2,{"CCC", "CCCCC", 'C'},22,"BSED",3},
            {1,{"DDD", "DDDDD", 'D'},23,"BSICT",4},
            {3,{"EEE", "EEEEE", 'E'},19,"BSIT",1},
            {2,{"EEE", "EEEEE", 'E'},19,"BSIT",1},
            {6,{"EEE", "EEEEE", 'E'},19,"BSIT",1}
    };

    populate(&P, studArr, sizeof(studArr)/sizeof(studArr[0]));
    // StudType delStud = deleteMinV1(&P);
    heapSort(&P);
    display(P);
    // printf("Deleted:\n");
    // displayStudent(delStud);


    return 0;
}

void init(POT *P) {
    P->last = -1;
}

void populate(POT *P, StudType arr[], int size) {
    int i;

    for (i = 0; i < size; i++)  
        insert(P, arr[i]);
}

void insert(POT *P, StudType data) {
    if (P->last < MAX - 1) {
        P->stud[++P->last] = data;
    }
}

void insertV1(POT *P, StudType data) {
    int cur, parent;
    StudType temp;

    if (P->last < MAX - 1) {
        P->stud[++P->last] = data;
        cur = P->last;
        parent = (cur - 1) / 2;

        while (cur > 0 && P->stud[cur].id < P->stud[parent].id ) {
            temp = P->stud[cur];
            P->stud[cur] = P->stud[parent];
            P->stud[parent] = temp;

            cur = parent;
            parent = (cur - 1) / 2;
        }
    }
}

void insertV2(POT *P, StudType data) {
    int cur, parent;

    if (P->last < MAX - 1) {
        cur = ++P->last;
        parent = (cur - 1) / 2;

        while (cur > 0 && P->stud[parent].id > data.id) {
            P->stud[cur] = P->stud[parent];
            cur = parent;
            parent = (cur - 1) / 2;
        }
        P->stud[cur] = data;
    }
}

StudType deleteMinV1(POT *P) {
    int cur, child;
    StudType retVal = {0,{"XXX", "XXXXX", 'X'},0,"XXXX",0}, temp;

    if (P->last > -1) {
        retVal = P->stud[0];
        P->stud[0] = P->stud[P->last--];

        int cur = 0;
        int child = 1;
        while (cur <= P->last && child <= P->last) {
            if (child + 1 <= P->last && P->stud[child].id > P->stud[child+1].id) {
                child++;
            }

            if (P->stud[cur].id < P->stud[child].id ) {
                break;
            }

            temp = P->stud[cur];
            P->stud[cur] = P->stud[child];
            P->stud[child] = temp;

            cur = child;
            child = 2 * cur + 1;
        }

    }
    return retVal;
}

StudType deleteMinV2(POT *P) {
    int cur, child;
    StudType retVal = {0,{"XXX", "XXXXX", 'X'},0,"XXXX",0}, temp;

    if (P->last > -1) {
        retVal = P->stud[0];
        temp = P->stud[P->last--];
        cur = 0;
        child = 1;
        while (cur <= P->last && child <=  P->last) {
            if (child + 1 <= P->last && P->stud[child].id > P->stud[child+1].id) {
                child++;
            } 
            if (temp.id < P->stud[child].id) {
                break;
            }
            P->stud[cur] = P->stud[child];
            cur = child;
            child = 2 * cur + 1;
        }
        P->stud[cur] = temp;
    } 
    return retVal;
}

void heapSort(POT *P) {
    StudType temp;
    int origLast = P->last;

    // version 1
    int i;
    P->last = -1;
    for (i = 0; i <= origLast; i++)
        insertV2(P, P->stud[i]);

    // version 2
    // minHeapify(P);
    
    while (P->last > -1) {
        temp = deleteMinV2(P);
        P->stud[P->last + 1] = temp;
    }
    P->last = origLast;
}

void minHeapify(POT *P) {
    int parent, cur, child;
    StudType temp;

    if (P->last > -1) {
        parent = (P->last - 1) / 2;
        while (parent >= 0) {
            cur = parent;
            child = 2 * cur + 1;
            while (child <= P->last) {
                if (child + 1 <= P->last && P->stud[child].id > P->stud[child+1].id) {
                    child++;
                }
                if (P->stud[cur].id < P->stud[child].id) {
                    break;
                }

                temp = P->stud[cur];
                P->stud[cur] = P->stud[child];
                P->stud[child] = temp;

                cur = child;
                child = 2 * cur + 1;
            }
            parent--;
        }
    }
}

void display(POT P) {
    int i;

    displayHeader();
    for (i = 0; i <= P.last; i++) {
        printf("%-10d", P.stud[i].id);
        printf("%-16s", P.stud[i].name.fname);
        printf("%-16s", P.stud[i].name.lname);
        printf("%-8d", P.stud[i].age);
        printf("%-8s", P.stud[i].course);
        printf("%-8d", P.stud[i].yr);
        printf("\n");
    }
}

void displayStudent(StudType stud) {
    printf("%-10d", stud.id);
    printf("%-16s", stud.name.fname);
    printf("%-16s", stud.name.lname);
    printf("%-8d", stud.age);
    printf("%-8s", stud.course);
    printf("%-8d", stud.yr);
    printf("\n");
}

void displayHeader() {
    printf("%-10s", "ID");
    printf("%-16s", "First Name");
    printf("%-16s", "Last Name");
    printf("%-8s", "Age");
    printf("%-8s", "Course");
    printf("%-8s", "Year Level");
    printf("\n");
}
