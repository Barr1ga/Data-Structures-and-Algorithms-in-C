#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef int ElemPos;
typedef int Elemtype;
typedef struct node {
    Elemtype data[MAX];
}BT;

Elemtype inputData();
void initBT(BT *tree);
Elemtype inputData();
BT preOrderCreate(BT *tree, ElemPos pos);
BT inOrderCreate(BT *tree, ElemPos pos);
BT postOrderCreate(BT *tree, ElemPos pos);
int display(BT arrayBT);
void recdisplayPreOrder(BT arrayBT, ElemPos pos);
void recdisplayInOrder(BT arrayBT, ElemPos pos);
void recdisplayPostOrder(BT arrayBT, ElemPos pos);
void virtualizeArray(BT arrayBT);

void initBT(BT *tree){
    int i;
    for(i=0; i<MAX; i++){
        tree->data[i]=-1;
    }
}

Elemtype inputData(){
    Elemtype ret;
    printf("*Enter -1 to stop*\n");
    printf("Child: ");
    scanf("%d", &ret);
    return ret;
}
 
BT preOrderCreate(BT *tree, ElemPos pos){
    Elemtype ret=inputData();
    if(ret!=-1){
        printf("\nPost Assigning data %d...\n", ret);
        tree->data[pos]=ret;
        
        printf("\nEnter LEFT child of parent %d[%d]\n ", pos, ret);
        preOrderCreate(tree, pos*2+1);

        printf("\nEnter RIGHT child of parent %d[%d]\n ", pos, ret);
        preOrderCreate(tree, pos*2+2);
    }
}     
             

BT inOrderCreate(BT *tree, ElemPos pos){
    Elemtype ret=inputData();
    if(ret!=-1){
        printf("\nEnter LEFT child of parent %d [%d]\n ", pos, ret);
        inOrderCreate(tree, pos*2+1);

        printf("\nIn Assigning data %d...\n", ret);
        tree->data[pos]=ret;

        printf("\nEnter RIGHT child of parent %d [%d]\n ", pos, ret);
        inOrderCreate(tree, pos*2+2);
    }
}   

BT postOrderCreate(BT *tree, ElemPos pos){
    Elemtype ret=inputData();
    if(ret!=-1){
        printf("\nEnter LEFT child of parent %d[%d]\n ", pos, ret);
        postOrderCreate(tree, pos*2+1);

        printf("\nEnter RIGHT child of parent %d[%d]\n ", pos, ret);
        postOrderCreate(tree, pos*2+2);

        printf("\nPost Assigning data %d...\n", ret);
        tree->data[pos]=ret;
    }
}   

// display

int display(BT arrayBT){
    int choose;
    ElemPos initpos=0; 
    printf("\n\nDisplay in...\n");
    printf("[0] Exit\n");
    printf("[1] Pre-order\n");
    printf("[2] In-order\n");
    printf("[3] Post-order\n");
    printf("[4] Virtualize array\n");

    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            printf("===========\n");
            printf("Pre-order\n");
            printf("===========\n");
            recdisplayPreOrder(arrayBT, initpos);
            break;
        case 2: 
            printf("===========\n");
            printf("In-order\n");
            printf("===========\n");
            recdisplayInOrder(arrayBT, initpos);
            break;
        case 3:
            printf("===========\n");
            printf("Post-order\n");
            printf("===========\n");
            recdisplayPostOrder(arrayBT, initpos);
            break;
        case 4:
            virtualizeArray(arrayBT);
            break;
    }
    return choose;
}

void recdisplayPreOrder(BT arrayBT, ElemPos pos){
    
    if(pos<MAX && arrayBT.data[pos]!=-1){
        printf("%d [%d]\n", pos, arrayBT.data[pos]);
        recdisplayPreOrder(arrayBT, pos*2+1);
        recdisplayPreOrder(arrayBT, pos*2+2);
    }
}

void recdisplayInOrder(BT arrayBT, ElemPos pos){
    
    if(pos<MAX && arrayBT.data[pos]!=-1){
        recdisplayInOrder(arrayBT, pos*2+1);
        printf("%d [%d]\n", pos, arrayBT.data[pos]);
        recdisplayInOrder(arrayBT, pos*2+2);
    }
}

void recdisplayPostOrder(BT arrayBT, ElemPos pos){
    
    if(pos<MAX && arrayBT.data[pos]!=-1){
        recdisplayPostOrder(arrayBT, pos*2+1);
        recdisplayPostOrder(arrayBT, pos*2+2);
        printf("%d [%d]\n", pos, arrayBT.data[pos]);
    }
}

void virtualizeArray(BT arrayBT){
    ElemPos i;
    printf("===========\n");
    printf("Array virt\n");
    printf("===========\n");
    for(i=0; i<MAX; i++){
        printf("%3d [%3d]\n", i, arrayBT.data[i]);
    }
    printf("===========\n");
}

void main(){
    BT arrayBT;
    ElemPos initpos=0;

    initBT(&arrayBT);
    int choose;
    printf("\n\nCreate Tree in...\n");
    printf("[1] Pre-order\n");
    printf("[2] In-order\n");
    printf("[3] Post-order\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            printf("Enter root node data\n");
            preOrderCreate(&arrayBT, initpos);
            break;
        case 2: 
            printf("Enter root node data\n");
            inOrderCreate(&arrayBT, initpos);
            break;
        case 3:
            printf("Enter root node data\n");
            postOrderCreate(&arrayBT, initpos);
            break;
    }
    
    do{
        choose=display(arrayBT);
    }while(choose!=0);
    
}