#include <stdio.h>
#include <stdlib.h>

void startMenu();
void insert();
void display();
void revDisplay();
void delete();
void deleteFirst();
void deleteEnd();
void deleteSpecific();

struct node {
    int info;
    struct node *pre;
    struct node *next;
};

struct node *start;

int main() {

    start = NULL;

    startMenu();

    return 0;
}

void startMenu() {
    
    int n;
    while (1)
    {
        printf("\n1. Insert in the list.");
        printf("\n2. Delete from the list.");
        printf("\n3. Display.");
        printf("\n4. Reverse Display.");
        printf("\n5. Exit.\n");

        scanf("%d", &n);

        if (n == 1)
            insert();
        else if (n == 2)
            delete();
        else if (n == 3)
            display();
        else if (n == 4)
            revDisplay();
        else
            exit(0);
    }
}


void insert() {

    int i;
    struct node *temp, *tmp;
    temp = malloc(sizeof(struct node));

    printf("\nEnter information: ");
    scanf("%d", &i);

    temp->info = i;

    if (start == NULL) {
        start = temp;
        start->pre = NULL;
        start->next = NULL;
    }
    else {
        tmp = start;

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = temp;
        temp->pre = tmp;
        temp->next = NULL;
    }
    display();
}

void display() {
    struct node *tmp;
    tmp = start;

    printf("\n");
    while (tmp != NULL) {
        printf("%d\n", tmp->info);
        tmp = tmp->next;
    }
}

void revDisplay() {
    struct node *tmp;
    tmp = start;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    while (tmp!= NULL) {
        printf("%d\n", tmp->info);
        tmp = tmp->pre;
    }
}

void delete() {

    int n;

    while (1) {
        printf("\n************* DELETE ****************");
        printf("\n1. Delete from the start of the list.");
        printf("\n2. Delete from the end of the list.");
        printf("\n3. Delete a specific element.");
        printf("\n4. Display.");
        printf("\n5. Go to start menu.\n");
        scanf("%d", &n);

        if (n == 1)
            deleteFirst();
        else if (n == 2)
            deleteEnd();
        else if (n == 3)
            deleteSpecific();
        else if (n == 4)
            display();
        else
            startMenu();
    }

}

void deleteFirst() {
    
    if (start == NULL)
        printf("\nUNDERFLOW!");
    else if (start->next == NULL)
        start = NULL;
    else {
        start = start->next;
        display();
    }
}

void deleteEnd() {
    struct node *trav;

    trav = start;

    if(start == NULL)
        printf("\nUNDERFLOW!");
    else if (start->next == NULL)
        start == NULL;
    else {
        while (trav->next != NULL)
            trav = trav->next;

        trav->pre->next = NULL;
        display();
    }
}

void deleteSpecific() {
    int element;
    struct node *trav;

    trav = start;

    printf("\nEnter element to delete: ");
    scanf("%d", &element);

    if (start == NULL)
        printf("UNDERFLOW!");
    else {
        while (trav != NULL && trav->info != element) {
            trav = trav->next;
        }

        if (trav == NULL) {
            printf("\nEntered element doesn't exist in the list.\n");
        }
        else if (trav == start) {
            if (start->next == NULL)
                start = NULL;
            else {
                start = start->next;
                display();
            }
        }
        else if (trav->next == NULL) {
            trav->pre->next = NULL;
            display();
        }
        else {
            trav->pre->next = trav->next;
            trav->next->pre = trav->pre;
            trav->next = NULL;
            trav->pre = NULL;
            trav = NULL;
            free(trav);
            display();
        }
    }
}