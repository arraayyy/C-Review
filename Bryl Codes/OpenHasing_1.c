#define SIZE 26

typedef struct{
    char FN[24], LN[16], MI;
}nameType;

typedef struct{
    nameType N;
    unsigned long idNumber;
    char course[5];
}studRec;

typedef struct node{
    studRec S;
    struct node *next;
}nodeType, *nPtr;

void init(Dictionary D)
{
    int i;
    for(i=0;i<SIZE;i++){
        D[i] = NULL;
    }
}

int hash(char LN[])
{
    return LN[0] - 'A'; /*0  for A, 2 for B, etc*/
}





Boolean isMember(Dictionary D, studRec S)
{
    int h;
    
    nPtr trav;
    h = hash(S.N.LN);
    
    for(trav = D[h];trav!=NULL && trav->S.idNumber != S.idNumber; trav=trav->next){}
    
    return (trav!=NULL)?TRUE:FALSE;
}










void deleteRec(Dictionary D, studRec S)
{
    nPtr *trav, temp;
    int h;
    
    h = hash(S.N.LN);
    
    if(isMember(D, S)==TRUE){
        for(trav = &D[h];*trav!=NULL && (*trav)->S.idNumber != S.idNumber ;trav = &(*trav)->next){}
        temp = (*trav);
        (*trav) = temp->next;
        free(temp);
    }else{
        printf("Element not in the set!\n");
    }
}

void insert(Dictionary D, studRec S)
{
    nPtr temp, *trav;
    int h;
    h = hash(S.N.LN);
    if(D[h] == NULL){
        D[h] = (nPtr)malloc(sizeof(nodeType));
        D[h]->S = S;
        D[h]->next = NULL;
    }else{
        if(isMember(D, S)==FALSE){
            for(trav = &D[h]; *trav!=NULL  && strcmp((*trav)->S.N.LN, S.N.LN) < 0;trav = &(*trav)->next){}
            temp = (nPtr)malloc(sizeof(nodeType));
            if(temp!=NULL){
                temp->S = S;
                temp->next = D[h];
                D[h] = temp;
            }
        }
        
    }
}
