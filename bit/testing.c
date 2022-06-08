#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    char elem[MAX];
    int last;
}*List;

// Write the code of the function that wil1 delete all even numbers in the given list and put them in a newly created list. The elements in the newly created
// list is sorted in ascending order, hence each element will be inserted in the sorted list. In addition, the newly created list will be returned to the call
// ing function.

List returnEvenSorted(List *L)
{
    int i;
    List retEven = (List)malloc(sizeof(struct node)); 
    for(i=0; i < L->last; i++){
        
    }
    return retEven;
}

int main () {
    List L = (List)malloc(sizeof(struct node));
    L->elem[0] = 2; 
    L->elem[1] = 3; 
    L->elem[2] = 1; 
    L->elem[3] = 43; 
    L->elem[4] = 123; 
    L->elem[5] = 23; 
    L->elem[6] = 2342; 
}