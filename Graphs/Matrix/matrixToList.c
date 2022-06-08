#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node
{
    int elem;
    struct node *next;
} nodetype, *ptr;

typedef ptr adjList[MAX];
typedef int matrix[MAX][MAX];

void initMatrix(matrix M)
{
    int i, k;
    for (i = 0; i < MAX; i++)
    {

        for (k = 0; k < MAX; k++)
        {
            M[i][k] = 0;
        }
    }
}

void displayMatrix(matrix M)
{
    int i, k;
    printf("  ");
    for (i = 0; i < MAX; i++)
    {
        printf("%3d", i);
    }
    printf("\n", i);
    for (i = 0; i < MAX; i++)
    {
        printf("%d |", i);
        for (k = 0; k < MAX; k++)
        {
            if (M[i][k])
            {
                printf("%3d", M[i][k]);
            }
            else
            {
                printf("  -");
            }
        }
        printf("\n");
    }
}

void insertDirectedMatrix(matrix M, int parent, int child)
{
    M[parent][child] = 1;
}

void insertUndirectedMatrix(matrix M, int parent, int child)
{
    M[parent][child] = 1;
    M[child][parent] = 1;
}

void initList(adjList L)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        L[i] = NULL;
    }
}

void displayList(adjList L)
{
    int i;
    ptr trav;
    for (i = 0; i < MAX; i++)
    {
        printf("%d |", i);
        for (trav = L[i]; trav != NULL; trav = trav->next)
        {
            printf("%3d", trav->elem);
        }
        printf("\n");
    }
}

void insertDirectedListLast(adjList L, int parent, int child)
{
    ptr *trav;
    for (trav = &L[parent]; *trav != NULL; trav = &(*trav)->next)
    {
    }

    if (*trav == NULL)
    {
        *trav = (ptr)malloc(sizeof(nodetype));
        if (*trav != NULL)
        {
            (*trav)->elem = child;
            (*trav)->next = NULL;
        }
    }
}

void insertDirectedListFirst(adjList L, int parent, int child)
{
    ptr temp;
    temp = (ptr)malloc(sizeof(nodetype));
    if (temp != NULL)
    {
        temp->elem = child;
        temp->next = L[parent];
        L[parent] = temp;
    }
}

void matrixToList(matrix M, adjList L)
{
    int i, k; // i = parent, k = child
    for (i = 0; i < MAX; i++)
    {
        for (k = 0; k < MAX; k++)
        {
            if (M[i][k] == 1)
            {
                insertDirectedListLast(L, i, k);
            }
        }
    }
}

void breakLine()
{
    printf("\n\n");
}

void main()
{
    matrix M;
    adjList L;
    initMatrix(M);
    displayMatrix(M);
    // insertDirectedMatrix(M, 2, 3);
    // insertDirectedMatrix(M, 3, 6);
    // insertDirectedMatrix(M, 3, 8);
    // insertDirectedMatrix(M, 2, 4);
    // insertDirectedMatrix(M, 4, 8);
    // displayMatrix(M);

    // breakLine();
    // initList(L);
    // displayList(L);

    // matrixToList(M, L);
    // displayList(L);

    insertUndirectedMatrix(M, 2, 3);
    insertUndirectedMatrix(M, 3, 6);
    insertUndirectedMatrix(M, 3, 8);
    insertUndirectedMatrix(M, 2, 4);
    insertUndirectedMatrix(M, 4, 8);
    displayMatrix(M);

    breakLine();
    initList(L);
    displayList(L);

    matrixToList(M, L);
    displayList(L);

}