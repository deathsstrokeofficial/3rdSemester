#include <stdio.h>
#include <stdlib.h>

void push();

int main()
{
    int ar[10], *top, n;

    printf("\nMaximum 10 element is allowed");

    top = NULL;

    while(1)
    {
        printf("\n 1. PUSH");
        printf("\n 2. EXIT\n");
        scanf("%d", &n);

        if (n==1)
            push();
        else
            exit(0);
    }
    return 0;
}

void push()
{

}
