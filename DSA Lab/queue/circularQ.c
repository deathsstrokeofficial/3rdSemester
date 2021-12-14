#include <stdio.h>
#include <stdlib.h>

struct test Qinsert(int *, struct test);
struct test Qdelete(int *, struct test);
void display(int *, struct test);

struct test
{
    int *front, *rear;
};

int main()
{
    int ar[10], n;

    struct test dsa;

    printf("\nAT MAX 10 ELEMENT IS ALLOWED.");

    dsa.front = NULL;
    dsa.rear = NULL;

    while(1)
    {
        printf("\n 1. QUEUE INSERT");
        printf("\n 2. QUEUE DELETE");
        printf("\n 3. EXIT\n");
        scanf("%d", &n);

        if (n == 1)
            dsa = Qinsert(ar, dsa);
        else if (n == 2)
            dsa = Qdelete(ar, dsa);
        else
            exit(0);

    }

    return 0;
}

struct test Qinsert(int *ar1, struct test dsa)
{
    int i;

    printf("\nEnter the data you want to insert: ");
    scanf("%d", &i);

    if (dsa.front == NULL && dsa.rear == NULL)
    {
        dsa.rear = &ar1[0];
        *dsa.rear = i;
        dsa.front = dsa.rear;
    }
    else
    {
        if ((dsa.rear == &ar1[9] & dsa.front == &ar1[0]) | (dsa.rear+1 == dsa.front))
        {
            printf("\nOVERFLOW");
        }
        else
        {
            if (dsa.rear == &ar1[9])
                dsa.rear = &ar1[0];
            else 
                dsa.rear++;
            *dsa.rear = i;
        }
    }
    display(ar1, dsa);
    return dsa;
}

void display(int *ar2, struct test dsa)
{
    int *i;
    
    if (dsa.rear < dsa.front) {
        for (i = dsa.front; i <= &ar2[9]; i++)
            printf("\n %d", *i);
        
        for (i = &arr2[0]; i <= dsa.rear; i++)
            printf("\n %d", *i);
    }
    else {
        for (i = dsa.front; i <= dsa.rear; i++)
            printf("\n %d", *i);
    }
}

struct test Qdelete(int *ar3, struct test dsa)
{
    if (dsa.front > dsa.rear || (dsa.front == NULL && dsa.rear == NULL))
    {
        printf("UNDERFLOW");
        dsa.front = NULL;
    }
    else
    {   if (dsa.front == dsa.rear)
        {
            dsa.rear = NULL;
            dsa.front++;
        }
        dsa.front++;
    }

    display(ar3, dsa);
    return dsa;
}
