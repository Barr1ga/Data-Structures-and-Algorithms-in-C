#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 9999999
#define VISITED 1

#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    // int NG[V][V] = {0};
    // int parent;         //  row number
    // int child;         //  col number
    // int edges = 0; // number of edges
    // int mark[V] = {0};
    // mark[0] = 1;

    // while (edges < V - 1)
    // {
    //     int min = INF;
    //     parent = 0;
    //     child = 0;

    //     for (int i = 0; i < V; i++)
    //     {
    //         //   find min edge that is not visited
    //         for (int j = 0; j < V; j++)
    //         {
    //             if (!mark[j] && G[i][j])
    //             {
    //                 if (min > G[i][j])
    //                 {
    //                     min = G[i][j];
    //                     parent = i;
    //                     child = j;
    //                 }
    //             }
    //         }
    //     }

    //     NG[parent][child] = G[parent][child];
    //     mark[child] = VISITED;
    //     edges++;
    // }

    // int NG[V][V] = {0}, mark[V] = {0};
    // int parent, start = 0, child, min, i, j, edgeCount = 0;

    // mark[start] = 1;

    // while (edgeCount != V - 1)
    // {
    //     min = INF;
    //     for (i = 0; i < V; i++)
    //     {
    //         for (j = 0; j < V; j++)
    //         {
    //             if (G[i][j] && !mark[j])
    //             {
    //                 if (G[i][j] < min)
    //                 {
    //                     min = G[i][j];
    //                     parent = i;
    //                     child = j;
    //                 }
    //             }
    //         }
    //     }
    //     NG[parent][child] = G[parent][child];
    //     mark[child] = VISITED; 
    //     edgeCount++;
    // }

    int NG[V][V] = {0}, min, mark[V] = {0}, i, j, parent, child, edgeCount = 0;
    int start = 0;
    mark[start] = 1;

    for ( ; edgeCount != V-1; edgeCount++) {
        for (min = INF, i=0; i<V; i++) {
            for (j=0; j<V; j++) {
                if (!mark[j] && mark[i] && G[i][j]) {
                    if (G[i][j] < min) {
                        min = G[i][j];
                        parent = i;
                        child = j;
                    }
                }
            }
        }

        NG[parent][child] = G[parent][child];
        mark[child] = VISITED;
    }

    // print result matrix
    printf("   ", parent);
    for (parent = 0; parent < V; parent++)
    {
        printf(" %3d", parent);
    }
    for (parent = 0; parent < V; parent++)
    {
        printf("\n%d |", parent);
        for (child = 0; child < V; child++)
        {
            if (NG[parent][child] == 0)
            {
                printf("   -");
            }
            else
            {
                printf("%4d", NG[parent][child]);
            }
        }
    }

    return 0;
}