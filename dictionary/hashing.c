#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define COUNT 20

typedef int Elemtype;
typedef int Elempos;

typedef struct node {
    Elemtype data;
    struct node *next;
}nodetype, *ptr;

typedef ptr dictionary[SIZE];

typedef Elemtype SET[COUNT];


Elemtype hash(Elemtype data);
void populate(dictionary D, SET A);
void populate(dictionary D, SET A);

Elemtype hash(Elemtype data){
    return data % 10;
}

void init(dictionary D){
    int i;
    for(i=0; i<SIZE; i++){
        D[i]=NULL;
    }
}

void populate(dictionary D, SET A){
    int i;
    Elempos pos;
    ptr *trav;
    
    for(i=0;i<SIZE;i++){
        pos=hash(A[i]);
        for(trav=&D[pos]; *trav!=NULL && (*trav)->data!=A[i]; trav=&(*trav)->next){
        }
        if(*trav==NULL){
            *trav=(ptr)calloc(1, sizeof(nodetype));
            if(*trav!=NULL){
                (*trav)->data=A[i];
                (*trav)->next=NULL;
            }
        }
    }
}

void insert(dictionary D, Elemtype data){
    Elempos pos;
    ptr *trav;
    pos = hash(data);

    for(trav=&D[pos]; *trav!=NULL && (*trav)->data!=data; trav=&(*trav)->next){
    }
    if(*trav==NULL){
        *trav=(ptr)calloc(1,sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->data=data;
            (*trav)->next=NULL;
        }
    }
}

void display(dictionary D){
    int i;
    ptr trav;
    printf("Dictionary\n");
    for(i=0; i<SIZE; i++){
        printf("%4d | ", i);
        for(trav=D[i]; trav!=NULL; trav=trav->next){
            printf("->%3d ",trav->data);
        }
        printf("\n");
    }
}


void main(){
    SET A={20,15,21,78,56,32,10,41,56,86,79,32,34,25,19};
    dictionary D;  
    


    init(D);
    populate(D, A);
    display(D);
    insert(D, 24);
    display(D);
}