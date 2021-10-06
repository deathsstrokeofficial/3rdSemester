#include <stdio.h>
#include <stdlib.h>

int * push(int *, int *);
int * pop(int *, int *);
void display(int *, int *);

int main()
{
    int ar[10], *top, n;

    printf("\nMaximum 10 element is allowed");

    top = NULL;

    while(1)
    {
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. EXIT\n");
        scanf("%d", &n);

        if (n==1)
            top = push(ar, top);
        else if (n==2)
            top = pop(ar, top);
        else
            exit(0);
    }
    return 0;
}

int * push(int *ar1, int *top)
{
    int i, j;

    printf("\nEnter the number you want to push: ");
    scanf("%d", &i);

    if (top == NULL)
    {
        top = &ar1[0];
        *top = i;
    }
    else
    {
        if (top == &ar1[9])
        {
            printf("\nOVERFLOW");
        }
        else
        {
            top++;
            *top = i;
        }
    }
    display(ar1, top);
    return top;
}

void display(int *ar2, int *top)
{

    int *i;
    for (i = top; i >= ar2; i--)
    {
        printf("\n%d", *i);
    }
}

int * pop(int *ar3, int *top)
{
    if (top == NULL)
    {
        printf("Underflow");
        return;
    }
    if (*top == ar3[0])
    {
        top = NULL;
        display(ar3, top);
        return top;
    }

    top--;
    display(ar3, top);
    return top;
}
