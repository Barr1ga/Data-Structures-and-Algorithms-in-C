#include <stdio.h>
#include <stdlib.h>

// n(n-1)/2
#define MAX_VERTEX 5
#define MAX 10
#define VISITED 1
#define UNVISITED 0

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

void displayMatrixV2(MATRIX M)
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

void displayMatrix(MATRIX_1 M)
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

void dfsIterative(MATRIX_1 M, int vertex)
{
    int stack[MAX_VERTEX + 1];
    int mark[MAX_VERTEX];
    int i, k, curr;

    for (i = 0; i < MAX_VERTEX; i++)
    {
        mark[i] = UNVISITED;
    }

    stack[0] = 1;
    stack[1] = vertex;
    mark[vertex] = VISITED;
    printf("%d ", vertex);

    while (stack[0] != 0)
    {
        curr = stack[stack[0]];
        for (i = 0; i < MAX_VERTEX; i++)
        {
            if (M[curr][i] == 1 && mark[i] != VISITED)
            {
                break;
            }
        }

        if (i == MAX_VERTEX)
        {
            stack[0]--;
        }
        else
        {
            stack[0]++;
            stack[stack[0]] = i;
            printf("%d ", i);
            mark[i] = VISITED;
        }
    }
}

void lineBreak()
{
    printf("\n\n");
}

void dfsV3(MATRIX_1 M, int vertex)
{
    int stack[MAX_VERTEX];
    int i, curr, top = 0;
    int mark[MAX_VERTEX] = {0};

    stack[top] = vertex;
    printf("%d ", vertex);

    while (top != -1)
    {
        // peek
        curr = stack[top];
        // mark
        mark[curr] = 1;

        for (i = 0; i < MAX_VERTEX; i++)
        {
            if (M[curr][i] && !mark[i])
            {
                break;
            }
        }

        if (i == MAX_VERTEX)
        {
            top--;
        }
        else
        {
            stack[++top] = i;
            printf("%d ", stack[top]);
        }
    }
}

void dfsV3Recursive(MATRIX_1 M, int vertex, int mark[])
{
    int i;
    printf("%d ", vertex);
    mark[vertex] = 1;
    for (i = 0; i < MAX_VERTEX; i++)
    {
        if (M[vertex][i] && !mark[i])
        {
            dfsV3Recursive(M, i, mark);
        }
    }
}

int main()
{
    EdgeList E = {{{1, 3}, {2, 3}, {3, 4}, {0, 1}, {3, 0}}, 5};
    MATRIX_1 M;
    initMatrix(M);
    // displayMatrix(M);
    toMatrix(M, E);
    displayMatrix(M);
    lineBreak();
    int mark[MAX_VERTEX] = {0};

    dfsV3(M, 1);
    lineBreak();

    dfsV3Recursive(M, 1, mark);

    // MATRIX ME;
    // initMatrixV2(&ME);
    // displayMatrix(M2);
    // // toMatrixV2(ME, E);
    // // displayMatrixV2(ME);
    // lineBreak();
    // // dfsIterative(M, 4);

    return 0;
}