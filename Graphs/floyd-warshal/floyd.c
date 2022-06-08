#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define INF 999

typedef int matrix[MAX][MAX];

void initMatrix(matrix M)
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            M[i][j] = INF;
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
            if (M[i][k] == INF)
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

void insertDirectedMatrix(matrix M, int parent, int child, int weight)
{
    M[parent][child] = weight;
}

void floyd(matrix M, matrix N)
{
    int i, j, k;

    // copy all
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            N[i][j] = M[i][j];
        }
    }

    // set centers 0
    for (i = 0; i < MAX; i++)
    {
        N[i][i] = 0;
    }

    // calculate
    for (k = 0; k < MAX; k++)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (N[i][k] + N[k][j] < N[i][j])
                {
                    N[i][j] = N[i][k] + N[k][j];
                }
            }
        }
    }
    displayMatrix(N);
}

void main()
{
    matrix M, N;
    initMatrix(M);
    insertDirectedMatrix(M, 0, 2, 3);
    insertDirectedMatrix(M, 1, 0, 5);
    insertDirectedMatrix(M, 1, 3, 7);
    insertDirectedMatrix(M, 1, 6, 6);
    insertDirectedMatrix(M, 2, 5, 2);
    insertDirectedMatrix(M, 4, 2, 4);
    insertDirectedMatrix(M, 4, 7, 5);
    insertDirectedMatrix(M, 5, 6, 4);
    insertDirectedMatrix(M, 6, 2, 2);
    insertDirectedMatrix(M, 6, 4, 4);
    displayMatrix(M);
    floyd(M, N);
}