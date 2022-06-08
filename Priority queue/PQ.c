#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef int Elemdata;
typedef int Elempos;

typedef struct{
    Elemdata elem[MAX];
    Elempos last;
}Heap;

void initHeap(Heap *H){
    H->last=-1;
    int i;
    for(i=0; i<MAX; i++){
        H->elemt[i]=-1;
    }
}

void insert(Heap *H, Elemdata data){
    Elempos index, parent;
    if(H->last<MAX-1){
        H->last++;
        index = H->last;
        parent = (index-1)/2;
        while(index>0 && H->elem[parent]>data){
            H->elemt[index] = H->elem[parent];
            parent = (parent-1)/2;
            index = (index-1)/2;
        }
        H->elem[index] = data;
    }
}

Elemdata deletemin(Heap *H){
    Elemdata ret, temp;
    Elempos trav, child;

    if(H->elem[0]!=-1){
        ret = H->elem[0];
        H->elem[0] = H->elem[H->last];
        H->last--;
        trav=0;
        child=1;

        while(child<=H->last){
            if(H->elem[child+1] < H->elem[child]){
                child++;
            }
            if(H->elem[child] > H->elem[trav]){
                temp = H->elem[trav];
                H->elem[trav] = H->elem[child];
                H->elem[child] = H->elem[temp];
                trav = child;
            }else{
                break;
            }
            child = child*2+1;
        }
    }
    return ret;
}