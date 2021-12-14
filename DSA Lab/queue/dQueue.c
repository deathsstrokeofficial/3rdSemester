#include <stdio.h>
#include <stdlib.h>

struct test QinsertFront(int *, struct test);
struct test QinsertRear(int *, struct test);
struct test QdeleteFront(int *, struct test);
struct test QdeleteRear(int *, struct test);
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
        printf("\n 1. QUEUE INSERT USING FRONT");
        printf("\n 2. QUEUE INSERT USING REAR");
        printf("\n 3. QUEUE DELETE USING FRONT");
        printf("\n 4. QUEUE DELETE USING REAR");
        printf("\n 5. EXIT\n");
        scanf("%d", &n);

        if (n == 1)
            dsa = QinsertFront(ar, dsa);
        else if (n == 2)
            dsa = QinsertRear(ar, dsa);
        else if (n == 3)
            dsa = QdeleteFront(ar, dsa);
        else if (n == 4)
            dsa = QdeleteRear(ar, dsa);
        else
            exit(0);

    }

    return 0;
}

struct test QinsertFront(int *ar1, struct test dsa)
{
    int i;

    printf("\nEnter the data you want to insert: ");
    scanf("%d", &i);

    if (dsa.front == NULL && dsa.rear == NULL)
    {
        dsa.front = &ar1[0];
        *dsa.front = i;
        dsa.rear = dsa.front;
    }
    else
    {
        if (dsa.front == &ar1[0])
        {
            printf("\nOVERFLOW");
        }
        else
        {
            dsa.front--;
            *dsa.front = i;
        }
    }
    display(ar1, dsa);
    return dsa;
}

struct test QinsertRear(int *ar1, struct test dsa)
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
        if (dsa.rear == &ar1[9])
        {
            printf("\nOVERFLOW");
        }
        else
        {
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

    for (i = dsa.front; i <= dsa.rear; i++)
        printf("\n %d", *i);
}

struct test QdeleteFront(int *ar3, struct test dsa)
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
        display(ar3, dsa);
    }

    return dsa;
}

struct test QdeleteRear(int *ar3, struct test dsa)
{
    if ((dsa.front == NULL) & (dsa.rear == NULL))
    {
        printf("UNDERFLOW");
    }
    else
    {   
        if (dsa.rear == dsa.front)
        {
            dsa.rear = NULL;
            dsa.front = NULL;
        }
        else {
            dsa.rear--;
            display(ar3, dsa);
        }
    }

    return dsa;
}
