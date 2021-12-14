#include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();

struct node {
    int info;
    struct node *link;
};

struct node *start;

int main() {

    int n;

    start = null;

    while(1) {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        scanf("%d", &n);

        if(n == 1)
            insert();
        else if (n == 2)
            delete();
        else if (n == 3)
            display();
        else
            exit(0);
    }
    return 0;
}

void insert()
{

}

void delete()
{

}

void display()
{

}