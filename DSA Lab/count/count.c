/*
    Use single linked list to write Count() function that 
    counts the number of times a given integer occurs in a list.
*/


#include <stdio.h>
#include <stdlib.h>
void Insert();
void Delete();
void display();
void Count();

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
        printf("\n 3. Count");
        printf("\n 4. Exit\n");
        scanf("%d", &n);

        if (n == 1)
            Insert();
        else if (n == 2)
            Delete();
        else if (n == 3)
            Count();
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
    // Count();
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
    printf("\n");
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

void Count() {
    int counter=1;
    struct node *trav, *temp, *check;

    trav = start;

    // Outer loop traverses the list to get individual integer.
    // Inner loop traverses the list to get the count of number of times each integer occurs.
    while (trav != NULL) {

        printf("\n%d - ", trav->info);
        temp = trav->link;

        while (temp != NULL) {
            if (temp->info == trav->info)
                counter++;
            
            temp = temp->link;
        }
        printf("%d", counter);
        counter = 1;
        trav = trav->link;

        check = start;
        while (trav != NULL && check->link != trav)  {
            if (check->info == trav->info)
                trav = trav->link;
            
            check = check->link;
        }
    }


}