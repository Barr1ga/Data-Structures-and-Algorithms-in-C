#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

typedef int UNI[MAX];
typedef int Elempos;
typedef int Elemdata;
typedef char SET;

void universalInit(UNI A){
    Elempos i;
    for(i=0; i<MAX; i++){
        A[i]=i+2;
    }
}

SET setComplement(SET C){
    return ~C;
}

SET setUnion(SET A, SET B){
    return A|B;
}

SET setIntersection(SET A, SET B){
    return A&B;
}

SET setDifference(SET A, SET B){
    return A&~B;
}

void setInsert(SET *C, Elempos index){
    if(index>-1 && index<MAX){
        *C = *C | (1 << index);
    }
}

void setInsertByNum(UNI U, SET *C, Elemdata num){
    Elempos i;
    if(num>-1 && num<MAX){
        for (i=0; i<MAX && U[i]!=num; i++){
        }
        if(i!=MAX){
            setInsert(C, i);
        }
    }
}

void insertThhis(SET *C, Elempos pos){
    if(pos>-1 && pos<MAX){
        *C = *C | (1 << pos);
    }
}

void setDelete(SET *C, Elempos index){
    if(index>-1 && index<MAX){
        *C = ~((~*C) | (1 << index-1));
    }
}

void setDeleteByNum(UNI U, SET *C, Elemdata num){
    Elempos i;
    for(i=0; i<MAX && U[i]!=num; i++){
        if(i<MAX){
            setDelete(C, i);
        }
    }
}

void displaySetBit(SET C){
    Elempos i;
    printf("{");
    for(i=8; i>0; i--){
        printf("%d", ((C >> (i-1)) & 1)? 1:0);
    }
    printf("}\n\n");
}

int findBit(SET C, Elempos pos){
    return ((C >> (pos-1)) & 1)? 1: 0;
}

void displaySetValues(UNI U, SET A){
    Elempos i;
    printf("{");
    for (i=MAX-1; i>0; i--){
        if(((A >> i) & 1) == 1){
            printf("%d", U[A]);
            if((i+1)!=MAX){
                printf(", ");
            }
        }
    }
    printf("}\n\n");
}

void universalIndex(){
    int i;
    printf("`````Index = ");
    for (i=MAX-1; i>=0; i--){
        printf("%3d", i);
    }
    printf("\n");
}

void displayUniversal(UNI U){
    Elempos i;
    
    printf("{");
    for (i=MAX-1; i>=0; i--){
        printf("%3d", U[i]);
    }
    printf("}\n\n");
}

void main(){
    UNI U;
    universalInit(U);
    SET A, B, UNION, INTER, DIFF, COMPA, COMPB;

    universalIndex();
    printf("Universal = "); 
    displayUniversal(U);

    setInsertByNum(U, &A, 2);
    setInsertByNum(U, &A, 4);
    setInsertByNum(U, &A, 5);
    setInsertByNum(U, &A, 6);
    setInsertByNum(U, &A, 9);

    setInsertByNum(U, &B, 3);
    setInsertByNum(U, &B, 4);
    setInsertByNum(U, &B, 5);
    setInsertByNum(U, &B, 8);
    setInsertByNum(U, &B, 7);
    
    printf("A = ");
    displaySetBit(A);

    printf("B = ");
    displaySetBit(B);

    UNION = setUnion(A, B);
    INTER = setIntersection(A, B);
    DIFF = setDifference(A, B);
    COMPA = setComplement(A);
    COMPB = setComplement(B);
    

    printf("SET UNION = ");
    displaySetBit(UNION);

    printf("SET INTER = ");
    displaySetBit(INTER);
    
    printf("SET DIFF = ");
    displaySetBit(DIFF);

    printf("SET COMP A = ");
    displaySetBit(COMPA);

    printf("SET COMP B = ");
    displaySetBit(COMPB);

}
