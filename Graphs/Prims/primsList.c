#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 9999999
#define VISITED 1
#define MAX 4

typedef struct node
{
    int weight;
    int elem;
    struct node *next;
} nodetype, *ptr;

typedef ptr list[MAX];

void initList(list L)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        L[i] = NULL;
    }
}

void br()
{
    printf("\n");
}

void insertFirst(list L, int parent, int child, int weight)
{
    ptr temp;
    temp = (ptr)malloc(sizeof(nodetype));
    if (temp != NULL)
    {
        temp->weight = weight;
        temp->elem = child;
        temp->next = L[parent];
        L[parent] = temp;
    }
}

void displayList(list L)
{
    int i;
    ptr trav;
    for (i = 0; i < MAX; i++)
    {
        printf("\n[%d] ", i);
        for (trav = L[i]; trav != NULL; trav = trav->next)
        {
            printf("[%d|%d] ", trav->elem, trav->weight);
        }
    }
}

void primsAlgorithm(list L, list primsL)
{
    int i, parent = 1, child, insert, min = INF, mark[MAX] = {0}, edgeCount;
    ptr trav;

    mark[parent] = VISITED;
    for (edgeCount = 0; edgeCount != MAX - 1; edgeCount++)
    {
        min = INF;
        for (i = 0; i < MAX; i++)
        {
            if (mark[i])
            {
                for (trav = L[i]; trav != NULL; trav = trav->next)
                {
                    if (!mark[trav->elem] && trav->weight < min)
                    {
                        
                        min = trav->weight;
                        parent = i;
                        child = trav->elem;
                    }
                }
            }
        }
        insertFirst(primsL, parent, child, min);
        insertFirst(primsL, child, parent, min);
        mark[child] = VISITED;
    }
}

void main()
{
    list L, primsL;
    initList(L);
    initList(primsL);

    // insertFirst(L, 0, 4, 3);
    // insertFirst(L, 0, 3, 4);
    // insertFirst(L, 0, 1, 6);
    // insertFirst(L, 1, 5, 8);
    // insertFirst(L, 2, 3, 7);
    // insertFirst(L, 2, 1, 3);
    // insertFirst(L, 3, 7, 9);
    // insertFirst(L, 3, 2, 4);
    // insertFirst(L, 4, 7, 2);
    // insertFirst(L, 5, 6, 1);
    // insertFirst(L, 5, 8, 6);
    // insertFirst(L, 6, 2, 5);
    // insertFirst(L, 6, 1, 8);
    // insertFirst(L, 8, 7, 6);

    insertFirst(L, 0, 1, 2);
    insertFirst(L, 0, 2, 4);
    insertFirst(L, 1, 2, 1);
    insertFirst(L, 2, 3, 3);
    insertFirst(L, 1, 0, 2);
    insertFirst(L, 2, 0, 4);
    insertFirst(L, 2, 1, 1);
    insertFirst(L, 3, 2, 3);
    displayList(L);
    primsAlgorithm(L, primsL);
    br();
    displayList(primsL);
}