#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef int ElemPos;
typedef int Elemtype;
typedef struct node {
    Elemtype data[MAX];
}BST;

void initBST(BST *arrayBST);
void insertBST(BST *arrayBST, Elemtype data);
Elemtype BSTmin(BST *arrayBST);
Elemtype BSTmax(BST *arrayBST);
int member(BST *arrayBST, Elemtype data);

void recursiveinsertBST(BST *arrayBST, ElemPos pos, Elemtype data);
Elemtype recBSTmin(BST *arrayBST, ElemPos pos);
Elemtype recBSTmax(BST *arrayBST, ElemPos pos);
int recursivemember(BST *arrayBST, ElemPos pos, Elemtype data);

void recdisplayPreOrder(BST arrayBST, ElemPos pos);
void recdisplayInOrder(BST arrayBST, ElemPos pos);
void recdisplayPostOrder(BST arrayBST, ElemPos pos);

void initBST(BST *arrayBST){
    int i;
    for(i=0; i<MAX; i++){
        arrayBST->data[i]=-1;
    }
}

void insertBST(BST *arrayBST, Elemtype data){
    ElemPos i=0;
    while(i<MAX && arrayBST->data[i]!=-1 && arrayBST->data[i]!=data){
        i=(arrayBST->data[i] < data)? i*2+2: i*2+1;
    }

    if(arrayBST->data[i]==-1){
        arrayBST->data[i]=data;
    }
}

Elemtype BSTmin(BST *arrayBST){
    ElemPos i;
    Elemtype ret;
    for(i=0; i<MAX &&  arrayBST->data[i*2+1]!=-1; i=i*2+1){
    }

    if(arrayBST->data[i*2+1]==-1){
        ret=arrayBST->data[i];
    }
    return ret;
}

Elemtype BSTmax(BST *arrayBST){
    ElemPos i;
    Elemtype ret;
    for(i=0; i<MAX &&  arrayBST->data[i*2+2]!=-1; i=i*2+2){
    }

    if(arrayBST->data[i*2+2]==-1){
        ret=arrayBST->data[i];
    }
    return ret;
}

int member(BST *arrayBST, Elemtype data){
    ElemPos i;
    for(i=0; i<MAX && arrayBST->data[i]!=data; i++){}
    return (i<MAX)? 1 : 0;
}


// Recursive

void recursiveinsertBST(BST *arrayBST, ElemPos pos, Elemtype data){
    if(pos<MAX && arrayBST->data[pos]!=-1 && arrayBST->data[pos]!=data){
        if(arrayBST->data[pos] < data){
            recursiveinsertBST(arrayBST, pos*2+2, data);
        }else{
            recursiveinsertBST(arrayBST, pos*2+1, data);
        }
    }else{
        arrayBST->data[pos]=data;
    }
}

Elemtype recBSTmin(BST *arrayBST, ElemPos pos){
    Elemtype ret;
    if(arrayBST->data[pos*2+1]!=-1){
        ret=recBSTmin(arrayBST, pos=pos*2+1);
    }
    return ret;
}

Elemtype recBSTmax(BST *arrayBST, ElemPos pos){
    Elemtype ret;
    if(arrayBST->data[pos*2+2]!=-1){
        ret=recBSTmin(arrayBST, pos=pos*2+2);
    }
    return ret;
}

int recursivemember(BST *arrayBST, ElemPos pos, Elemtype data){
    if(pos<MAX && arrayBST->data[pos]!=data){
        recursivemember(arrayBST, pos+1, data);
    }
    return (pos<MAX)? 1 : 0;
}




// display
 
void recdisplayPreOrder(BST arrayBST, ElemPos pos){
    if(pos<MAX && arrayBST.data[pos]!=-1){
        printf("%d [%d]\n", pos, arrayBST.data[pos]);
        recdisplayPreOrder(arrayBST, pos*2+1);
        recdisplayPreOrder(arrayBST, pos*2+2);
    }
}

void recdisplayInOrder(BST arrayBST, ElemPos pos){
    if(pos<MAX && arrayBST.data[pos]!=-1){
        recdisplayInOrder(arrayBST, pos*2+1);
        printf("%d [%d]\n", pos, arrayBST.data[pos]);
        recdisplayInOrder(arrayBST, pos*2+2);
    }
}

void recdisplayPostOrder(BST arrayBST, ElemPos pos){
    if(pos<MAX && arrayBST.data[pos]!=-1){
        recdisplayPostOrder(arrayBST, pos*2+1);
        recdisplayPostOrder(arrayBST, pos*2+2);
        printf("%d [%d]\n", pos, arrayBST.data[pos]);
    }
}

void virtualizeArray(BST arrayBST){
    ElemPos i;
    printf("===========\n");
    printf("Array virt\n");
    printf("===========\n");
    for(i=0; i<MAX; i++){
        printf("%3d [%3d]\n", i, arrayBST.data[i]);
    }
    printf("===========\n");
}



void main(){
    BST tree, tree2;
    ElemPos initpos=0;

    initBST(&tree);
    initBST(&tree2);

    printf("NONREC INSERT\n");
	
	insertBST(&tree, 10);
    insertBST(&tree, 6);
    insertBST(&tree, 17);
    insertBST(&tree, 4);
    insertBST(&tree, 8);
    insertBST(&tree, 7);
    insertBST(&tree, 9);
    insertBST(&tree, 12);
    insertBST(&tree, 19);

    virtualizeArray(tree);
	system("PAUSE");

    printf("recursive preOrder\n");
    recdisplayPreOrder(tree, initpos);
    
    printf("recursive preOrder\n");
    recdisplayInOrder(tree, initpos);

    printf("recursive preOrder\n");
    recdisplayPostOrder(tree, initpos);
    
    // printf("REC INSERT\n");
    // virtualizeArray(tree2);
	// system("PAUSE");
	
	// recursiveinsertBST(&tree2, initpos, 10);
    // recursiveinsertBST(&tree2, initpos, 6);
    // recursiveinsertBST(&tree2, initpos, 17);
    // recursiveinsertBST(&tree2, initpos, 4);
    // recursiveinsertBST(&tree2, initpos, 8);
    // recursiveinsertBST(&tree2, initpos, 7);
    // recursiveinsertBST(&tree2, initpos, 9);
    // recursiveinsertBST(&tree2, initpos, 12);
    // recursiveinsertBST(&tree2, initpos, 19);

    // virtualizeArray(tree2);
	// system("PAUSE");


	
}


// void recursiveDeleteBST(BST *arrayBST, ElemPos pos, Elemtype data){
//     ElemPos i=0;
//     if(arrayBST->data[i]!=-1 && arrayBST->data[i]!=data){
//         if(arrayBST->data[i] < data){
//             recursiveDeleteBST(arrayBST, pos*2+2, data);
//         }else{
//             recursiveDeleteBST(arrayBST, pos*2+1, data);
//         }
//     }else if(arrayBST->data[i]!=-1){
//         if(arrayBST->data[i*2+1]==-1){
//             recDelBSTmin(arrayBST, i*2+2, data);

//         }
//     }

//     while(arrayBST->data[i]!=-1 && arrayBST->data[i]!=data){
//         i=(arrayBST->data[i] < data)? i*2+2: i*2+1;
//     }

// }

// void recDelBSTmin(BST *arrayBST, ElemPos pos, Elemtype data){
//     if(arrayBST->data[pos*2+1]!=-1){
//         recDelBSTmin(arrayBST, pos*2+1, data);
//     }
//     if(arrayBST->data[pos*2+2]!=-1){
//         recDelBSTmin(arrayBST, pos*2+2, data);
//     }
    
    
// }
