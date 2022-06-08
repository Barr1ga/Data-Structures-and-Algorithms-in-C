#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

typedef int SET[MAX];
typedef int Elempos;

SET* setInit(SET A){
    Elempos i;
    for(i=0; i<MAX; i++){
        A[i]=0;
    }
}

SET* setUnion(SET A, SET B){
    Elempos i;
    SET *C;
    C=(SET *)calloc(1, sizeof(SET));
    if(C!=NULL){
        for(i=0; i<MAX; i++){
            (*C)[i]=A[i] | B[i];
        }
    }
    return C;
}

SET* setIntersection(SET A, SET B){
    Elempos i;
    SET *C;
    C=(SET *)calloc(1, sizeof(SET));
    if(C!=NULL){
        for(i=0; i<MAX; i++){
            (*C)[i]=A[i] & B[i];
        }
    }
    return C;
}

SET* setDifference(SET A, SET B){
    Elempos i;
    SET *C;
    C=(SET *)calloc(1, sizeof(SET));
    if(C!=NULL){
        for(i=0; i<MAX; i++){
            (*C)[i]=A[i] &~ B[i];
        }
    }
    return C;
}

void setInsert(SET C, Elempos pos){
    if(pos<MAX){
        C[pos]|=1;
    }
}

void setDelete(SET C, Elempos pos){
    if(pos<MAX){
        C[pos]&=0;
    }
}

void displaySet(SET A){
    Elempos i;
    printf("{");
    for (i=0; i<MAX; i++){
        if(A[i]==1){
            printf("%d", i);
            if((i+1)!=MAX){
                printf(", ");
            }
        }
    }
    printf("}\n");
}

void displaySetRes(SET *A){
    Elempos i;
    printf("{");
    for (i=0; i<MAX; i++){
        if((*A)[i]==1){
            printf("%d", i);
            if((i+1)!=MAX){
                printf(", ");
            }
        }
    }
    printf("}\n");
}

void main(){
    SET A, B, *UNION, *INTER, *DIFF;
    setInit(A);
    setInsert(A, 2);
    setInsert(A, 1);
    setInsert(A, 3);
    setInsert(A, 4);
    setInsert(A, 8);
    setInsert(A, 6);
    setInsert(A, 9);

    printf("SET A = ");
    displaySet(A);


    setInit(B);

    setInsert(B, 1);
    setInsert(B, 5);
    setInsert(B, 7);
    setInsert(B, 3);
    setInsert(B, 6);
    setInsert(B, 9);
    setInsert(B, 4);
  
    printf("SET B = ");
    displaySet(B);

    UNION = setUnion(A, B);
    INTER = setIntersection(A, B);
    DIFF = setDifference(A, B);

    printf("SET UNION = ");
    displaySetRes(UNION);

    printf("SET INTER = ");
    displaySetRes(INTER);
    
    printf("SET DIFF = ");
    displaySetRes(DIFF);
}