#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define INF 999
#define VISITED 1

#define MAX 5

int G[MAX][MAX] = {
    {INF, 30, 25, INF, 50},
    {30, INF, INF, 90, 30},
    {25, INF, INF, 40, INF},
    {INF, 90, 40, INF, 10},
    {50, 30, INF, 10, INF}};

int main()
{
    int start = 2;
    int k, i;
    int curr, mark[MAX] = {0}, distance[MAX], min;
    memcpy(distance, G[start], sizeof(int) * MAX);

    for (k=0; k<MAX-1; k++) {
        min = INF;
        for (i=0; i<MAX; i++) {
            if (!mark[i] &&distance[i] < min) {
                min = distance[i];
                curr = i;
            }
        }

        for (i=0; i<MAX; i++) {
            if (!mark[i] && G[curr][i] + distance[curr] < distance[i]) {
                distance[i] = G[curr][i] + distance[curr];
            }
        }
    }

    // print matrix
    printf("   ");
    for (i = 0; i < MAX; i++)
    {
        printf(" %3d", i);
    }
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d |", i);
        for (k = 0; k < MAX; k++)
        {
            if (G[i][k] == INF)
            {
                printf("   -");
            }
            else
            {
                printf("%4d", G[i][k]);
            }
        }
    }

    // print distance
    printf("\n\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", distance[i]);
    }

    return 0;
}