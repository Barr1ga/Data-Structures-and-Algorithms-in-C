#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int Elemtype;
typedef int Elempos;
typedef int SET;

typedef struct{
    Elemtype elem;
    Elempos link;
}stype, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    Elempos avail;
}VH;

SET setUnion(SET A, SET B, VH *vheap){
    SET C=-1, *trav;
    trav=&C;

    while(A!=-1 && B!=-1){
        *trav=vheap.avail;
        if(*trav!=-1){
            vheap->avail=vheap.H[vheap->avail].link;
            if(vheap->H[A].elem < vheap->H[B].elem){
                vheap->H[*trav].elem = vheap->H[A].elem;
                A=vheap->H[A].linkl;
            }
        }
        
    }
}