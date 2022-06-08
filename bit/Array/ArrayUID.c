#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int Elemtype;
typedef int Elempos;

typedef struct{
    Elemtype content[MAX];
    int count;
}SET;

void initSet(SET *this){
    this->count=0;
}
    
SET setUnion(SET A, SET B);
SET setIntersection(SET A, SET B);

SET setUnion(SET A, SET B){
    SET C;
    initSet(&C);
    Elempos a=0, b=0;   
    while(a<A.count && b<B.count){
        if(A.content[a] < B.content[b]){
            C.content[C.count]=A.content[a];
            a++;
            C.count++;
        }else{
            if(A.content[a]==B.content[b]){
                a++;
            }
            C.content[C.count]=B.content[b];
            b++;
        }
        C.count++;
    }
    if(b<B.count){
        A=B;
        a=b;
    }
    while(a<A.count){
        C.content[C.count]=A.content[a];
        a++;
        C.count++;
    }
    return C;
}

SET setIntersection(SET A, SET B){
    SET C;
    initSet(&C);
    Elempos a=0, b=0;

    for(a=0; a<A.count; a++){
        for(b=0; b<B.count && B.content[b]<A.content[a]; b++){
        }
        if(B.content[b]==A.content[a]){
            C.content[C.count]=A.content[a];
            C.count++;
        }
    }
    return C;
}

SET insert(SET *S, Elemtype contentElem){
    if(S->count<MAX){
        S->content[S->count]=contentElem;
        S->count++;
    }
}

// A-B
SET setDifference(SET A, SET B){
    SET C;
    initSet(&C);
    Elempos a=0, b=0;

    for(a=0; a<A.count; a++){
        for(b=0; b<B.count && B.content[b]<A.content[a]; b++){
        }
        if(B.content[b]!=A.content[a]){
            C.content[C.count]=A.content[a];
            C.count++;
        }
    }
    return C;
}