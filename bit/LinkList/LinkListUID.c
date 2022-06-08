#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int Elemtype;
typedef int Elempos;

typedef struct node{
    Elemtype data;
    struct node *next;
}setNodeType, *SET;



SET setUnion(SET A, SET B){
    SET C=NULL, *trav;
    trav=&C;
    
    while(A!=NULL && B!=NULL){
        *trav=(SET)calloc(1, sizeof(setNodeType));
        if(*trav!=NULL){
            if(A->data < B->data){
                (*trav)->data=A->data;
                A=A->next;
            }else{
                if(A->data==B->data){
                    A=A->next;
                }
                (*trav)->data=B->data;
                B=B->next;
            }
            trav=&(*trav)->next;
        }
    }

    if(A==NULL && B!=NULL){
        A=B;
    }

    while(A!=NULL){
        *trav=(SET)calloc(1, sizeof(setNodeType));
        if(*trav!=NULL){
            (*trav)->data=A->data;
            trav=&(*trav)->next;
            A=A->next;
        }
    }
    *trav=NULL;
    return C;
}

SET setIntersection(SET A, SET B){
    SET C=NULL, *trav, travB;
    trav=&C;

    for(; A!=NULL; A=A->next){
        for(travB=B; travB!=NULL && travB->data<A->data; travB=travB->next){
        }
        if(travB!=NULL && travB->data==A->data){
            *trav=(SET)calloc(1, sizeof(setNodeType));
            if(*trav!=NULL){
                (*trav)->data=A->data;
                trav=&(*trav)->next;
            }
        }
    }
    *trav=NULL;
    return C;
}

SET insert(SET *S, Elemtype data){
    SET *trav, temp;
    for(trav=S; *trav!=NULL; trav=&(*trav)->next){
    }
    *trav=(SET)calloc(1, sizeof(setNodeType));
    if(*trav!=NULL){
        (*trav)->data=data;
    }
}

SET setDifference(SET A, SET B){
    SET C=NULL, *trav, travB;
    trav=&C;

    for(; A!=NULL; A=A->next){
        for(travB=B; *trav!=NULL && travB->data<A->data; travB=travB->next){}

        if(travB!=NULL && travB->data!=A->data){
            *trav=(SET)calloc(1, sizeof(setNodeType));
            if(*trav!=NULL){
                (*trav)->data=A->data;
                trav=&(*trav)->next;
            }
        }
    }
    *trav=NULL;
    return C;
}