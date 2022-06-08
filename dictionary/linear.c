
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 9
#define COUNT 10

typedef int Elemtype;
typedef int Elempos;

typedef Elemtype table[SIZE];
typedef Elemtype SET[COUNT];

Elemtype hash(Elemtype data);

Elemtype hash(Elemtype data){
    return data % 10;
}

void init(table D){
    int i;
    for(i=0; i<SIZE; i++){
        D[i]=-1;
    }
}

void populate(table D, SET A){
    int i, j;
    Elempos pos;
    
    for(i=0;i<SIZE;i++){
        pos=hash(A[i]);


        if(D[pos]==-1){
            D[pos]=A[i];
        }else if(D[pos]!=-1){
            for(j=pos+1; D[j]!=-1 && D[j]!=A[i]; j=(j+1) % SIZE){
            }
            if(j<SIZE){
                D[j]=A[i];
            }
        }else{
            printf("full")
        }
        
    }
}
// 012345

void display(table D){
    int i;
    printf("Dictionary\n");
    for(i=0; i<SIZE; i++){
        printf("%4d | %4d", i, D[i]);
        printf("\n");
    }
}


void main(){
    SET A={11,15,21,78,41,1,51,61,91};
    table D;  

    init(D);
    display(D);
    populate(D, A);
    display(D);

}


void insert(Dictionary D, char bits) {
    int hash_val = hash(bits), trav, origVal;
    origVal = hash_val;

    if(D->bits[hash_val]==EMPTY || D->bits[hash_val]==DELETED){
        D-bits[hash_val] = bits;
    }else{
        for (trav = hash_val+1;
            trav!=origVal && D->bits[trav]!=bits && D->bits[trav]!=EMPTY && D->bits[trav]!=DELETED;
            trav = (trav + 1) % MAX) {
        }
        if(D->bits[trav]==EMPTY || D->bits[trav]==DELETED){
            D->bits[trav] = bits;
        }else{
            // full
        }
    }
}

ItemList* getHeavyItmes(Locker *L, float threshold){
    ItemList *trav, temp, newList=NULL;
    for(trav=L->IL, newtrav=&newList; *trav!=NULL; *trav=(*trav)->nextItem){
        if((*trav)->item.weight > threshold) {
            temp = *trav;
            *trav = temp->nextItem;
            temp->nextItem = newList;
            newList = temp;
        }
    }
    return newList
}

void depositItem(Locker *L, char studID, ItemDets item){
    ItemList *trav, temp;
    if(strcmp(studID, L->owner.studID) == 0) {
        for(trav=&L->IL; *trav!=NULL && (*trav)->IL->item.weight > item.weight; *trav=(*trav)->nextItem) {
        }
        if(*trav!=NULL){
            temp = malloc(sizeof(ItemNode));
            if(temp!=NULL){
                temp->nextItem = *trav;
                temp = item;
                *trav = temp;
            }
        }
    }
}