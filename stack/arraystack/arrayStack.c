#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 10
#define TRUE 1
#define FALSE 0
#define MAX 30

typedef int Boolean;

typedef struct{
    char f[NAME];
    char m;
    char l[NAME];
}Fullname;

typedef struct{
    int ID;
    Fullname name;
    Boolean active;
}Person;

typedef struct{
    Person info;
}Node, *NP;

typedef struct VHeap{
    NP memory;//[]
    int top;
}*VH;

typedef int LList;

typedef int Top;

typedef struct{
    int head;
    int tail;
}Queue;




Boolean initVHeapZeroToMax(VH* heap);

void inputarrrecord(VH arrheap, int top);

// ARRAY STACK IMPLEMENTATION
//REDO THIS IMPLEMENTATION
//ARR STACK HAS NO VIRTUAL HEAP

void initarrstack(VH arrheap){
    int i;
    arrheap->memory=malloc(MAX * sizeof(Node));
    arrheap->top=-1;
}

void visualizearrheap(VH arrheap){
    int i;
    printf("\n%15s | %15s\n", "INDEX", "ELEM");
    for(i=MAX; i>=0 ; i--){
        printf("%15d | %15d\n", i, arrheap->memory[i].info.ID);
    }
    printf("top [%d]", arrheap->top);
}

void push(VH arrheap){
    if(arrheap->top!=MAX-1){
        arrheap->top+=1;
        inputarrrecord(arrheap, arrheap->top);
    }
}

void inputarrrecord(VH arrheap, int top){
    printf("\nEnter record input:\n");
    printf("\nID:\n");       scanf("%d", &(arrheap->memory[top].info.ID));
    arrheap->memory->info.active=1;
}

void poparrfirst(VH arrheap){
    if(arrheap->top!=-1){
        arrheap->top-=1;
    }
}

Node arrpeek(VH arrheap){
    Node ret;
    ret=arrheap->memory[arrheap->top-1];
    return ret;
}

void insertbottom(VH arrheap){
    int i;
    arrheap->top+=1;
    if(arrheap->top!=-1){
        for(i=arrheap->top; i>0; i--){
            arrheap->memory[i].info=arrheap->memory[i-1].info;
        }
    }
    inputarrrecord(arrheap, 0);
} 

//only when sorted




void main(){
    struct VHeap arrheap;
    initarrstack(&arrheap);

    visualizearrheap(&arrheap);
    push(&arrheap);
    push(&arrheap);
    push(&arrheap);
    

    visualizearrheap(&arrheap);

}


