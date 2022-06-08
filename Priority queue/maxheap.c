#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Elemdata;
typedef int Elempos;

typedef struct
{
    Elemdata elem[MAX];
    Elempos last;
} Heap;

// init
// insert
// delete
// display

void initHeap(Heap *H)
{
    int i;
    H->last = -1;
    for (i = 0; i < MAX; i++)
    {
        H->elem[i] = -1;
    }
}

void display(Heap H)
{
    int i;
    printf("\n\nHeap\n");
    printf("%4s | %4s\n", "indx", "data");
    for (i = 0; i < MAX; i++)
    {
        printf("%4d | %4d\n", i, H.elem[i]);
    }
    printf("last = %d", H.last);
}

void insert(Heap *H, Elemdata data)
{
    int i, index, temp;

    if (H->last < MAX - 1)
    {
        H->last++;
        H->elem[H->last] = data;

        for (index = H->last; index > 0 && H->elem[(index - 1) / 2] < data; index = (index - 1) / 2)
        {
            temp = H->elem[((index - 1) / 2)];
            H->elem[((index - 1) / 2)] = H->elem[index];
            H->elem[index] = temp;
        }
    }
}

void deleteMax(Heap *H)
{
    int index, child, temp;
    H->elem[0] = H->elem[H->last];
    H->last--;
    index = 0;
    child = index * 2 + 1;

    while (child < H->last)
    {
        if (H->elem[index * 2 + 2] > H->elem[index * 2 + 1])
        {
            child++;
        }

        if (H->elem[child] > H->elem[index])
        {
            temp = H->elem[child];
            H->elem[child] = H->elem[index];
            H->elem[index] = temp;
            index = child;
            child = index * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void heapsort(Heap *H, int arr[])
{
    int i, index, child, temp;
    // insert
    for (i = 0; i < MAX; i++)
    {
        if (H->last < MAX - 1)
        {
            H->last++;
            H->elem[H->last] = arr[i];
            for (index = H->last; index > 0 && H->elem[index] > H->elem[(index - 1) / 2]; index = (index - 1) / 2)
            {
                temp = H->elem[index];
                H->elem[index] = H->elem[(index - 1) / 2];
                H->elem[(index - 1) / 2] = temp;
            }
        }
    }
    display(*H);
    // delete
    for (i = 0; i < MAX; i++)
    {
        temp = H->elem[0];
        H->elem[0] = H->elem[H->last];
        H->elem[H->last] = temp;
        H->last--;
        index = 0;
        child = 1;
        while (child < H->last)
        {
            if (H->elem[index * 2 + 2] > H->elem[index * 2 + 1])
            {
                child++;
            }
            if (H->elem[child] > H->elem[index])
            {
                temp = H->elem[index];
                H->elem[index] = H->elem[child];
                H->elem[child] = temp;
                index = child;
                child = index * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
}

void heapify(Heap *B, int arr[])
{
    int index, trav, child, temp;
    // insert
    for (index = 0; index < MAX; index++)
    {
        B->elem[index] = arr[index];
        B->last++;
    }

    // heapify
    if (B->last != -1)
    {
        for (index = (B->last - 1) / 2; index >= 0; index--)
        {
            trav = index;
            child = trav * 2 + 1;
            while (child <= B->last)
            {
                if (child + 1 <= B->last && B->elem[child] < B->elem[child + 1])
                {
                    child++;
                }
                if (B->elem[child] > B->elem[trav])
                {
                    temp = B->elem[child];
                    B->elem[child] = B->elem[trav];
                    B->elem[trav] = temp;
                    trav = child;
                    child = trav * 2 + 1;
                }
                else
                {
                    // work around to break out of only while loop
                    child = B->last + 1;
                }
            }
        }
    }
}

void main()
{
    Heap H;
    Heap A;
    Heap B;
    int arr[MAX] = {54, 23, 62, 22, 11, 13, 62, 32, 33, 21};

    // 25,19,20,28,19,14,17,32,15
    // initHeap(&H);
    // display(H);
    // insert(&H, 33);
    // insert(&H, 25);
    // insert(&H, 20);
    // insert(&H, 15);
    // insert(&H, 19);
    // insert(&H, 18);
    // insert(&H, 40);
    // insert(&H, 61);
    // display(H);
    // deleteMax(&H);
    // display(H);

    // initHeap(&A);
    // display(A);
    // heapsort(&A, arr);
    // display(A);

    initHeap(&B);

    display(B);
    heapify(&B, arr);
    display(B);
}