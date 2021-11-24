#define SIZE 7
#define EMPTY -1
#define DELETED -2

typedef struct{
    char FN[24], LN[16], MI;
}nameType;

typedef struct{
    nameType name;
    char course[5];
    int yearLevel;
    unsigned long idNumber;
}studType;

typedef studType Dictionary[SIZE];

init()

void initDictionary(Dictionary D)
{
    int i;
    for(i=0;i<SIZE;i++){
        D[i].yearLevel = EMPTY;
    }
}
hash()

int hash(unsigned long x)
{
    int sum;
    while (x!=0){
        sum +=(x%10);
        x/=10;
 }
    return sum % SIZE;
}

isMember()

Boolean isMember(Dictionary D, studType P)
{
    int x, hv = hash(P.idNumber);

    Boolean retval = FALSE;
    
    if(D[hv].idNumber == P.idNumber){
        retval = TRUE;
    }else{
        x = (hv+1)%SIZE;
        while(x!=hv && D[x].idNumber!= P.idNumber){
            x = (x+1)%SIZE;
        }
        retval = (D[hv].idNumber == P.idNumber)?TRUE:FALSE;
    }
    
    return retval;
}

insert()

void insert(Dictionary D, studType P)
{
    int hv, x, ctr = 0;
    
    hv = hash(P.idNumber);
    
    if(isMember(D,P)==FALSE){
        if(D[hv].yearLevel == EMPTY || D[hv].yearLevel == DELETED){
            D[hv] = P;
        }else{
            x = (hv+1)%SIZE;
            while(x!=hv && D[x].yearLevel!=EMPTY && D[x].yearLevel!=DELETED){
                x = (x+1)%SIZE;
            }
            D[x] = P;
        }
    }
}   

delete()

void deleteDictionary(Dictionary D, studType P)
{
    int hv, x, ctr = 0;
    hv = hash(P.idNumber);

    if(D[hv].idNumber == P.idNumber){
        D[hv].yearLevel = DELETED;
    }else{
        x = (hv+1)%SIZE;
        while(x != hv && D[x].yearLevel != EMPTY && D[x].idNumber!=P.idNumber){
            x = (x+1)%SIZE;
        }
        if(D[x].idNumber == P.idNumber){
            D[x].yearLevel = DELETED;
        }
    }
}
