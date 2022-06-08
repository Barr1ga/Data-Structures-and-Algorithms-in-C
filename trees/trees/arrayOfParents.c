#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int Elemtype;
typedef int Elempos;
typedef struct node{
    Elemtype data[MAX];
}TREE;

void initTree(TREE *tree){
    int i;
    for(i=0; i<MAX; i++){
        Tree->data[i]=-1;
    }
}

void inputNode(TREE *tree){
    Elempos pos;
    pritnf("\nInsert to child: ");
    scanf("%d", &pos);
    pritnf("\nInsert to child: ");
    scanf("%d", &(tree)->data[pos]);
}

void insertParent(TREE *tree){
    
}