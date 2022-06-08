#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

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
    if(arrayBST->data[pos*2+1]!=-1 && pos<MAX){
        ret=recBSTmin(arrayBST, pos=pos*2+1);
    }else{
        ret=arrayBST->data[pos];
    }
    return ret;
}

Elemtype recBSTmax(BST *arrayBST, ElemPos pos){
    Elemtype ret;
    if(arrayBST->data[pos*2+2]!=-1 && pos<MAX){
        ret=recBSTmax(arrayBST, pos=pos*2+2);
    }else{
        ret=arrayBST->data[pos];
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



void main (){
    BST arrayBST;
    Elemtype data, ret;
    ElemPos initpos=0;
    //10 5 8 17 12 19
    initBST(&arrayBST);
    int choose;
    do{
        system("CLS");
        printf("\n\nDo operation...\n");
        printf("[0] Exit\n");
        printf("[1] Insert\n");
        printf("[2] Get Min\n");
        printf("[3] Get Max\n");
        printf("[4] Is Member\n");
        printf("[5] Recursive Insert\n");
        printf("[6] Recursive Get Min\n");
        printf("[7] Recursive Get Max\n");
        printf("[8] Recursive Is Member\n");
        printf("[9] preOrder\n");
        printf("[10] inOrder\n");
        printf("[11] postOrder\n");
        printf("[12] visualize\n");
        printf("Choose: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBST(&arrayBST, data);
                break;
            case 2:
                ret=BSTmin(&arrayBST);
                printf("Is min = [%d]", ret);
                system("PAUSE");
                break;
            case 3:
                ret=BSTmax(&arrayBST);
                printf("Is max = [%d]", ret);
                system("PAUSE");
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                ret=member(&arrayBST, data);
                printf("Is member = [%d]", ret);
                system("PAUSE");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                recursiveinsertBST(&arrayBST, initpos, data);
                break;
            case 6:
                ret=recBSTmin(&arrayBST, initpos);
                printf("Is min = [%d]", ret);
                system("PAUSE");
                break;
            case 7:
                ret=recBSTmax(&arrayBST, initpos);
                printf("Is max = [%d]", ret);
                system("PAUSE");
                break;
            case 8:
                printf("Enter data: ");
                scanf("%d", &data);
                recursivemember(&arrayBST, initpos, data);
                printf("Is member = [%d]", ret);
                system("PAUSE");
                break;
            case 9:
                recdisplayPreOrder(arrayBST, initpos);
                system("PAUSE");
                break;
            case 10:
                recdisplayInOrder(arrayBST, initpos);
                system("PAUSE");
                break;
            case 11:
                recdisplayPostOrder(arrayBST, initpos);
                system("PAUSE");
                break;
            case 12:
                virtualizeArray(arrayBST);
                system("PAUSE");
        }
    }while(choose!=0);
}



