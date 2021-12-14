#include <stdio.h>
#include <stdlib.h>

void push();
void display();
void pop();

struct node
{
    int n;
    struct node *link;
};

struct node *start;

int main()
{
    int m;

    while (1)
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. Exit\n");

        scanf("%d", &m);

        if (m == 1)
            push();
        else if (m == 2)
            pop();
        else
            exit(0);
    }

    return 0;
}

void push()
{
    struct node *test;
    int l;
    test = malloc(sizeof(struct node));

    printf("\n Enter the information: ");
    scanf("%d", &l);

    test->n = l;
    test->link = NULL;

    if (start == NULL)
    {
        start = test;
    }
    else
    {
        test->link = start;
        start = test;
    }
    display();
}

void display()
{
    struct node *test;
    test = start;

    while (test != NULL)
    {
        printf("\n %d", test->n);
        test = test->link;
    }
}

void pop()
{
    struct node *test;
    test = start;

    if (test == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        test = test->link;
        start = test;
    }
    display();

}