#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define VISITED 1
#define UNVISITED 0

typedef int matrix[MAX][MAX];

typedef struct
{
    int elem[MAX];
    int front;
    int back;
} queue;

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
    printf("\n\n   ");
    for (i = 0; i < MAX; i++)
    {
        printf(" %3d", i);
    }
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d |", i);
        for (k = 0; k < MAX; k++)
        {
            if (M[i][k] == UNVISITED)
            {
                printf("   -");
            }
            else
            {
                printf("%4d", M[i][k]);
            }
        }
    }
}

void insert(matrix M, int parent, int child)
{
    M[parent][child] = 1;
}

void initQueue(queue *Q)
{
    Q->front = 0;
    Q->back = -1;
}

void initMark(int mark[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        mark[i] = UNVISITED;
    }
}

void bfs(matrix M, int vertex)
{
    int i, curr, mark[MAX];
    queue Q;

    initQueue(&Q);
    initMark(mark);
    Q.back = (Q.back + 1) % MAX;
    Q.elem[Q.back] = vertex;

    while ((Q.back + 1) % MAX != Q.front)
    {
        curr = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAX;
        printf("%d ", curr);

        for (i = 0; i < MAX; i++)
        {
            if (M[curr][i] == 1 && mark[i] != VISITED && mark[i] != 2)
            {
                Q.back = (Q.back + 1) % MAX;
                Q.elem[Q.back] = i;
                mark[Q.elem[Q.back]] = VISITED;
            }
        }
        mark[curr] = 2;
    }
}

void lineBreak()
{
    printf("\n\n");
}

void main()
{

    matrix M;
    initMatrix(M);
    insert(M, 0, 4);
    insert(M, 1, 0);
    insert(M, 1, 3);
    insert(M, 2, 1);
    insert(M, 2, 3);
    insert(M, 3, 4);

    displayMatrix(M);

    lineBreak();
    bfs(M, 2);
}