#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define VISITED -1
#define UNVISITED -2
#define EXPLORED 0

typedef struct node
{
    int elem;
    struct node *next;
} nodetype, *ptr;

typedef ptr graph[MAX];

typedef struct
{
    int elem[MAX];
    int front;
    int back;
} queue;

void init(graph G)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        G[i] = NULL;
    }
}

void insert(graph G, int parent, int elem)
{
    ptr temp;
    temp = (ptr)malloc(sizeof(nodetype));
    if (temp != NULL)
    {
        temp->elem = elem;
        temp->next = G[parent];
        G[parent] = temp;
    }
}

void initMark(int Q[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        Q[i] = UNVISITED;
    }
}

void displayMark(int Q[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", Q[i]);
    }
}

void bfs(graph G, int vertex)
{
    int mark[MAX] = {0};
    queue Q;
    int curr;
    ptr trav;

    Q.front = 0;
    Q.back = -1;

    Q.back = (Q.back + 1) % MAX;
    Q.elem[Q.back] = vertex;
    mark[vertex] = VISITED;

    // while not empty DS
    while ((Q.back + 1) % MAX != Q.front)
    {
        curr = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAX;
        printf("%d ", curr);

        for (trav = G[curr]; trav != NULL; trav = trav->next)
        {
            if (!mark[trav->elem])
            {
                Q.back = (Q.back + 1) % MAX;
                Q.elem[Q.back] = trav->elem;
                mark[trav->elem] = VISITED;
            }
        }
    }
}


void displayList(graph G)
{
    int i;
    ptr trav;
    for (i = 0; i < MAX; i++)
    {
        printf("\n[%d] ", i);
        for (trav = G[i]; trav != NULL; trav = trav->next)
        {
            printf("%d -> ", trav->elem);
        }
    }
}

void main()
{
    graph G;
    init(G);
    int mark[MAX];
    initMark(mark);
    // insert(G, 0, 4);
    // insert(G, 0, 3);
    // insert(G, 0, 1);
    // insert(G, 1, 5);
    // insert(G, 2, 3);
    // insert(G, 2, 1);
    // insert(G, 3, 7);
    // insert(G, 3, 2);
    // insert(G, 4, 7);
    // insert(G, 5, 6);
    // insert(G, 5, 8);
    // insert(G, 6, 2);
    // insert(G, 6, 1);
    // insert(G, 8, 7);
    insert(G, 1, 3);
    insert(G, 1, 2);
    insert(G, 2, 3);
    insert(G, 3, 4);
    displayList(G);
    printf("\n\n");
    bfs(G, 1);
    printf("\n\n");

    printf("\n\n");
    bfsRecursive(G, 1, mark);
    // dfs(G, 1, mark);
}