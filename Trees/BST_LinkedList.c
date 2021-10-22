#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;
typedef struct node {
    Elemtype elem;
    struct node *left;
    struct node *right;
}nodetype, *BST;

void initBST(BST *head);

void insertBST(BST *head, Elemtype data);
void deleteBST(BST *head, Elemtype data);
void DelBSTmin(BST *head);
void DelBSTmax(BST *head);
int member(BST *head, Elemtype data);
Elemtype min(BST head);
Elemtype max(BST head);

void recursiveInsertBST(BST *head, Elemtype data);
void recursiveDeleteBST(BST *head, Elemtype data);
Elemtype recDelBSTmin(BST *head);
Elemtype recDelBSTmax(BST *head);
int recursiveMember(BST head, Elemtype data);
Elemtype recursiveMin(BST head);
Elemtype recursiveMax(BST head);

void preOrder(BST head);
void inOrder(BST head);
void postOrder(BST head);

void initBST(BST *head){
    *head = NULL;
}

// Non recursive

void insertBTS(BST *head, Elemtype data){
    BST *trav=head;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav = ((*trav)->elem < data)? &(*trav)->right : &(*trav)->left;
    }
    if(*trav==NULL){
        *trav=(BST)calloc(1, sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->elem=data;
        }
    }
}

void deleteBST(BST *head, Elemtype data){
    BST *trav=head, *trav2, temp;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav = ((*trav)->elem < data)? &(*trav)->right : &(*trav)->left;
    }

    if(*trav!=NULL){
        if((*trav)->left==NULL){
            temp=*trav;
            *trav=temp->right;
            free(temp);
        }else if((*trav)->right==NULL){
            temp=*trav;
            *trav=temp->left;
            free(temp);
        }else{
            for(trav2=&(*trav)->right; (*trav2)->left!=NULL; trav2=&(*trav2)->left){}
            temp=*trav2;
            *trav2=temp->right;
            (*trav)->elem=temp->elem;
            free(temp);
        }
    }
}

void DelBSTmin(BST *head){
    BST *trav=head, temp;
    while((*trav)->left!=NULL){
        trav=&(*trav)->left;
    }
    if(*trav!=NULL){
        temp=*trav;
        *trav=(*trav)->right;
        free(temp);
    }
}

void DelBSTmax(BST *head){
    BST *trav=head, temp;
    while((*trav)->right!=NULL){
        trav=&(*trav)->right;
    }
    if(*trav!=NULL){
        temp=*trav;
        *trav=(*trav)->left;
        free(temp);
    }
}

int member(BST *head, Elemtype data){
    BST *trav=head;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav=((*trav)->elem < data)? &(*trav)->right: &(*trav)->left;
    }
    return (*trav==NULL)? 1 : 0;
}

Elemtype min(BST head){
    BST trav=head;
    while(trav->left!=NULL){
        trav=trav->left;
    }
    return trav->elem;
}

Elemtype max(BST head){
    BST trav=head;
    while(trav->right!=NULL){
        trav=trav->right;
    }
    return trav->elem;
}


// Recursive

void recursiveInsertBST(BST *head, Elemtype data){
    BST *trav=head;

    if(*trav!=NULL && (*trav)->elem!=data){
        if((*trav)->elem < data){
            recursiveInsertBST(&(*trav)->right, data);
        }else{ 
            recursiveInsertBST(&(*trav)->left, data);
        }
    }else{
        *trav=(BST)calloc(1, sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->elem=data;
        }
    }
}

void recursiveDeleteBST(BST *head, Elemtype data){
    BST *trav, temp;
    if(*trav!=NULL && (*trav)->elem!=data){
        if((*trav)->elem < data){
            recursiveDeleteBST(&(*trav)->right, data);
        }else{
            recursiveDeleteBST(&(*trav)->left, data);
        }
    }else{
        if((*trav)->left == NULL){
            temp=*trav;
            *trav=temp->right;
            free(temp);
        }else if((*trav)->right == NULL){
            temp=*trav;
            *trav=temp->left;
            free(temp); 
        }else{
            temp=*trav;
            (*trav)->elem=recDelBSTmin(&(*trav)->right);
        }
    }
}

Elemtype recDelBSTmin(BST *head){
    BST *trav=head, temp;
    Elemtype ret;
    if((*trav)->left!=NULL){
        ret=recDelBSTmin(&(*trav)->left);
    }else{
        temp=*trav;
        *trav=temp->right;
        ret=temp->elem;
        free(temp);
    }
    return ret;
}

Elemtype recDelBSTmax(BST *head){
    BST *trav=head, temp;
    Elemtype ret;
    if((*trav)->right!=NULL){
        ret=recDelBSTmin(&(*trav)->right);
    }else{
        temp=*trav;
        *trav=temp->left;
        ret=temp->elem;
        free(temp);
    }
    return ret;
}

int recursiveMember(BST head, Elemtype data){
    BST trav=head;
    Elemtype ret=0;
    if(trav!=NULL && (trav)->elem!=data){
        if(trav->elem < data){
            ret=recursiveMember(trav->right, data);
        }else{
            ret=recursiveMember(trav->left, data);
        }
    }else{
        ret=1;
    }
}

Elemtype recursiveMin(BST head){
    Elemtype ret;
    if(head->left!=NULL){
        recursiveMin(head->left);
    }
    ret=head->elem;
    return ret;
}

Elemtype recursiveMax(BST head){
    Elemtype ret;
    if(head->right!=NULL){
        recursiveMin(head->right);
    }
    ret=head->elem;
    return ret;
}

void preOrder(BST head){
    if(head!=NULL){
        printf("[%d] ", head->elem);
        preOrder(head->left);
        preOrder(head->right);
    }
}//10 6 1 0 4 3 5 7 8 9 17 12 11 19

void inOrder(BST head){
    if(head!=NULL){
        InOrder(head->left);
        printf("[%d] ", head->elem);
        InOrder(head->right);

    }
}//0 1 3 4 5 6 7 8 9 10 11 12 17 19
 
void postOrder(BST head){
    if(head!=NULL){
        postOrder(head->left);
        postOrder(head->right);
        printf("[%d] ", head->elem);
    }
}//0 3 5 4 1 9 8 7 6 11 12 19 17 10
