#include <stdio.h>
#include <stdlib.h>
void Insert();
void Delete();
void display();

struct node
{
    int info;
    struct node *link;
};

struct node *start;


int main(void) {

    int n;
    
    while (1)
    {
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Exit\n");
        scanf("%d", &n);

        if (n == 1)
            Insert();
        else if (n == 2)
            Delete();
        else
            exit(0);
    }

    return 0;
}

void Insert()
{
    int i;
    struct node *test, *test1;
    test = malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &i);

    test->info = i;
    test->link = NULL;

    if (start == NULL)
    {
        start = test;
    }
    else
    {
        test1 = start;
        while (test1->link != NULL)
        {
            test1 = test1->link;
        }

        test1->link = test;
    }
    display();
}

void display()
{
    struct node *test;

    test = start;

    while (test != NULL)
    {
        printf("\n %d", test->info);
        test = test->link;
    }
}


void Delete ()
{
    struct node *test;
    test = start;

    if (test == NULL)
    {
        printf("\nUNDERFLOW!");
    }
    else if (test->link == NULL)
    {
        start = NULL;
    }
    else
    {
        while (test->link->link != NULL)
        {
            test = test->link;
        }

        test->link = NULL;
    }
    display();
}