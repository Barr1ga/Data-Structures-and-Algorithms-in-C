#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNBit(char value, int N);

// finding the Nth bit
int findNBit(char value, int N){
    return (value >> (N-1) & 1)? 1 : 0;
}

// 78
// 128=
// 64 =1
// 32 =
// 16 =
// 8  =1
// 4  =1
// 2  =1
// 1  =

// 01001110
// 01001110

void displayRet(int num){
    printf("[%d]\n", num);
}

void displayBitv1(char value){
    unsigned int mask;
    for(mask = 1 << ((sizeof(char)*8)-1); mask>0; mask>>=1){
        printf("%d", (value & mask)? 1: 0);
    }
    printf("\n%d", value);
}

void displayBitv2(char value){
    int N;
    for(N=sizeof(char)*8-1; N>=0; N--){
        printf("%d", (value >> (N) & 1)? 1 : 0);
    }
    printf("\n%d", value);
}

// void displayBitv2(char value){
//     int N;
//     for(N=sizeof(char)*8; N>0; N--){
//         printf("%d", (value >> (N-1) & 1)? 1 : 0);
//     }
//     printf("\n%d", value);
// }



void main (){
    char value=78;
    int num;

    num=findNBit(value, 2);
    displayRet(num);

    displayBitv1(value);
    printf("\n");
    displayBitv2(value);
}

// 8
// 01001110
// 00000001



// 78  
// 128 = 
// 64  = 1
// 32  = 
// 16  =  
// 8   = 1
// 4   = 1
// 2   = 1
// 1   = 