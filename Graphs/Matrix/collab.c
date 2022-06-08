#include <stdio.h>
#include <stdlib.h>

// n(n-1)/2
#define MAX_VERTEX 5
#define MAX 10

typedef struct
{
    int vertex;
    int adj_vertex;
} EdgeType;

typedef struct
{
    EdgeType edge[MAX];
    int edge_count;
} EdgeList;

typedef int **MATRIX;
typedef int MATRIX_1[MAX_VERTEX][MAX_VERTEX];

void initMatrix(MATRIX_1 M)
{
    int i, k;
    for (i = 0; i < MAX_VERTEX; i++)
    {
        for (k = 0; k < MAX_VERTEX; k++)
        {
            M[i][k] = 0;
        }
    }
}

void initMatrixV2(MATRIX *M)
{
    int i;
    *M = (MATRIX)calloc(MAX_VERTEX, sizeof(int *));

    for (i = 0; i < MAX_VERTEX; i++)
    {
        (*M)[i] = (int *)calloc(MAX_VERTEX, sizeof(int));
    }
}

void displayMatrix(MATRIX M)
{
    int i, k;
    printf("\n\n  ");
    for (i = 0; i < MAX_VERTEX; i++)
    {
        printf(" %3d", i);
    }
    for (i = 0; i < MAX_VERTEX; i++)
    {
        printf("\n%d |", i);
        for (k = 0; k < MAX_VERTEX; k++)
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

void insertDirectedMatrix(MATRIX_1 M, int parent, int child)
{
    M[parent][child] = 1;
}

void insertUndirectedMatrix(MATRIX_1 M, int parent, int child)
{
    M[parent][child] = 1;
    M[child][parent] = 1;
}

void insertUndirectedMatrixV2(MATRIX M, int parent, int child)
{
    M[parent][child] = 1;
    M[child][parent] = 1;
}

void toMatrix(MATRIX_1 M, EdgeList E)
{
    int i;
    for (i = 0; i < E.edge_count; i++)
    {
        insertUndirectedMatrix(M, E.edge[i].vertex, E.edge[i].adj_vertex);
    }
}

void toMatrixV2(MATRIX M, EdgeList E)
{
    int i;
    for (i = 0; i < E.edge_count; i++)
    {
        insertUndirectedMatrixV2(M, E.edge[i].vertex, E.edge[i].adj_vertex);
    }
}

int main()
{
    EdgeList E = {{{1, 3}, {2, 3}, {3, 4}, {0, 1}, {3, 0}}, 5};
    MATRIX_1 M, M2;
    // initMatrix(M);
    // displayMatrix(M);
    // toMatrix(M, E);
    // displayMatrix(M);

    MATRIX ME;
    initMatrixV2(ME);
    // displayMatrix(M2);
    toMatrixV2(ME, E);
    displayMatrix(ME);

    return 0;
}