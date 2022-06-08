void display(AdjList A)
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (A[i] == NULL)
        {
            printf("[%d] NULL");
        }
        else
        {
            printf("[%d] ", i);
        }
        for (NodePtr trav = A[i]; trav != NULL; trav = trav->next)
        {
            if (A[i] == NULL)
            {
                printf("NULL");
            }
            else
            {
                printf("%d", trav->vertex);
            }
            if (trav->next->next != NULL)
            {
                printf(" ->");
            }
        }
        printf("\n", i);
    }
}