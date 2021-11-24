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
void insertV1(POT *P, StudType data); // via swapping
void insertV2(POT *P, StudType data); // via shifting
StudType deleteMaxV1(POT *P); // via swapping
StudType deleteMaxV2(POT *P); // via shifting
void display(POT P);
void displayStudent(StudType stud);
void heapSort(POT *P);
void maxHeapify(POT *P);
void displayHeader();

int main () {
    POT P;
    init(&P);
    StudType studArr[] = {
            {1,{"AAA", "AAAAA", 'A'},20,"BSCS",2},
            {2,{"BBB", "BBBBB", 'B'},21,"BSCS",1},
            {3,{"CCC", "CCCCC", 'C'},22,"BSED",3},
            {4,{"DDD", "DDDDD", 'D'},23,"BSICT",4},
            {5,{"EEE", "EEEEE", 'E'},19,"BSIT",1},
            {6,{"EEE", "EEEEE", 'E'},19,"BSIT",1},
            {7,{"EEE", "EEEEE", 'E'},19,"BSIT",1}
    };

    populate(&P, studArr, sizeof(studArr)/sizeof(studArr[0]));
    
    // StudType delStud = deleteMaxV2(&P);
    // display(P);
    // printf("Deleted:\n");
    // displayStudent(delStud);
    heapSort(&P);
    // printf("Max Heapify: \n");
    // printf("Insert: \n");
    // maxHeapify(&P);
    display(P);

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

        while (cur > 0 && P->stud[cur].id > P->stud[parent].id) {
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

        while (cur > 0 && data.id > P->stud[parent].id) {
            P->stud[cur] = P->stud[parent];
            cur = parent;
            parent = (cur - 1) / 2;
        }
        P->stud[cur] = data;
    }
}

StudType deleteMaxV1(POT *P) {
    int cur, child;
    StudType retVal =  {0,{"XXX", "XXXXX", 'X'},0,"XXXX",0}, temp;

    if (P->last > -1) {
        retVal = P->stud[0];
        P->stud[0] = P->stud[P->last--];
        cur = 0;
        child = 1;

        while (cur <= P->last && child <= P->last) {
            if (child + 1 <= P->last && P->stud[child].id < P->stud[child + 1].id) {
                child++;
            }

            if (P->stud[cur].id > P->stud[child].id) {
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

StudType deleteMaxV2(POT *P) {
    int cur, child;

    StudType retVal =  {0,{"XXX", "XXXXX", 'X'},0,"XXXX",0}, temp;
    if (P->last > -1) {
        retVal = P->stud[0];
        temp = P->stud[P->last--];
        cur = 0;
        child = 1;

        while (cur <= P->last && child <= P->last) {
            if (child + 1 <= P->last && P->stud[child].id < P->stud[child + 1].id) {
                child++;
            }

            if (temp.id > P->stud[child].id) {
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
    int origLast = P->last;

    // version 1
    int i;
    P->last = -1;
    for (i = 0; i <= origLast; i++)
        insertV1(P, P->stud[i]);

    // version 2
    // maxHeapify(P);
    while (P->last > -1) {
        StudType temp = deleteMaxV2(P);
        P->stud[P->last + 1] = temp;
    }
    P->last = origLast;
}

void maxHeapify(POT *P) {
    int cur, parent, child;
    StudType temp;

    if (P->last > -1) {
        parent = (P->last - 1) / 2;
        while (parent >= 0) {
            cur = parent;
            child = cur * 2 + 1;
            while (child <= P->last) {
                if (child + 1 <= P->last && P->stud[child].id < P->stud[child+1].id) {
                    child++;
                }
                if (P->stud[child].id < P->stud[cur].id) {
                    break;
                } 
                 
                temp = P->stud[child];
                P->stud[child] =  P->stud[cur];
                P->stud[cur] = temp;  

                cur = child;
                child = cur * 2 + 1; 
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
