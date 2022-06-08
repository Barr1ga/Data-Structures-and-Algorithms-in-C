#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int Elemtype;
typedef int Elempos;

typedef struct child{
    Elemtype data;
    struct node *next;
}*ChildrenList;

typedef struct node{
    Elemtype label;
    Elempos parent;
    ChildrenList childList;
}TreeNode;

typedef struct node{
    Elempos root;
    TreeNode TN[MAX];
}Tree;

void initTree(Tree *T){
    int i;
    T->root=-1;
    for(i=0; i<MAX; i++){
        T->TN[i].label=-2;
        T->TN[i].childList=NULL;
        T->TN[i].parent=-2;
    }
}

void insertLeaf(Tree *T, Elemtype parent, Elemtype data){
    ChildrenList *trav;
    Elempos i;
    for(i=0; i<MAX && T->TN[i].label!=-2; i++){
    }
    T->TN[i].label=data;
    T->TN[i].parent=;


    if(T->TN[i].parent!=-2 && T->TN[data].parent==-2){
        T->TN[data].parent=parent;
        for(trav=&(T->TN[parent].childList); *trav!=NULL; trav=&(*trav)->next){}
        *trav=malloc(sizeof(child));
        (*trav)->data=data;
        (*trav)->next=NULL;
    }
}

void deleteLeaf(Tree *T, Elemtype data){
    Elempos i;
    ChildrenList *trav;
    if(T->TN[data].childList!=NULL){
        for(trav=&(T->TN[data]))
    }
}
