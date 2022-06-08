#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int matrix[MAX][MAX];

void initMatrix(matrix M)
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            M[i][j] = 0;
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
            if (M[i][k] == 0)
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

void insertDirectedMatrix(matrix M, int parent, int child)
{
    M[parent][child] = 1;
}

void warshall(matrix M, matrix N)
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

    // calculate
    for (k = 0; k < MAX; k++)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (N[i][j] == 0)
                {
                    N[i][j] = N[i][k] == 0 && N[k][j] == 0 ? 1 : 0;
                }
            }
        }
    }

    displayMatrix(N);
}

void main()
{
    matrix N;

    matrix M = {
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}};

    initMatrix(M);
    // insertDirectedMatrix(M, 0, 2);
    // insertDirectedMatrix(M, 1, 0);
    // insertDirectedMatrix(M, 1, 3);
    // insertDirectedMatrix(M, 1, 6);
    // insertDirectedMatrix(M, 2, 5);
    // insertDirectedMatrix(M, 4, 2);
    // insertDirectedMatrix(M, 4, 7);
    // insertDirectedMatrix(M, 5, 6);
    // insertDirectedMatrix(M, 6, 2);
    // insertDirectedMatrix(M, 6, 4);
    displayMatrix(M);
    warshall(M, N);
}