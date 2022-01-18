#include <stdio.h>
#include <stdlib.h>
void Display();
void Insert();
void Delete();
struct node;
void split(struct node**, struct node**);
void displayLeftPart(struct node*);
void displayRightPart(struct node*);

struct node {
    int data;
    struct node* link;
};

struct node* start;
int isSplited = 0;



int main() {

    struct node* leftSplit;
    struct node* rightSplit;
    
    int n;
    
    printf("Choose one of the following:\n");

    while(1) {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4. Split");
        printf("\n5. Display left split");
        printf("\n6. Display right split");
        printf("\n7. Exit\n");
        
        scanf("%d", &n);
        
        switch(n) {
            case 1: Insert();
            break;
            case 2: if(isSplited==1){
                printf("Can't Display, list isSplited. Use Split Display Options\n");
            }else
                Display();
            break;
            case 3: Delete();
            break;
            case 4: split(&leftSplit , &rightSplit);
            break;
            case 5: displayLeftPart(leftSplit);
            break;
            case 6: displayRightPart(rightSplit);
            break;
            default: printf("Invalid Option\n");
        }
    }
    return 0;
}

void split(struct node** left, struct node** right) {
    if(isSplited == 1){
        free(*right);
       
    }
    
    if(start == NULL) {
        printf("Can't Split an empty list \n");
        isSplited = 0;
        return;
    }
    if(start->link == NULL) {
        isSplited = 0;
        printf("Minimum two elements required to split the list");
        return;
    }
    *left = start;
    
    int numberOfNodes = 0;
    struct node* temp;
    temp = start;
    
    while(temp != NULL) {
        numberOfNodes++;
        temp = temp->link;
    }
    
    int remainder = 0;
    if(numberOfNodes % 2 != 0) {
        remainder = 1;
    }
    
    struct node* trav;
    trav = start;
    int i = 1;
        
    while(trav != NULL && i != (numberOfNodes/2) + remainder) {
        i++;
        trav = trav->link;
    }
        
    *right = trav->link;
    trav->link = NULL;
    
    printf("Split Successful\n");
    isSplited = 1;
    
}

void displayLeftPart(struct node* left) {
    if(start == NULL){
        printf("Can't display an empty list\n");
        return;
    }
    if(isSplited == 0) {
         printf("List is not Splited\n");
        return;
    }
   
    struct node* temp;
    temp = left;
    while(temp != NULL) {
        
        printf("%d ", temp->data);
        temp = temp->link;
        
    }
}

void displayRightPart(struct node* right) {
     if(start == NULL) {
        printf("Can't display an empty list\n");
        return;
    }
    if(isSplited == 0) {
        printf("List is not Splited\n");
        return;
    }
    
    struct node* temp;
    temp = right;
    while(temp!= NULL) {
        
        printf("%d ", temp->data);
        temp = temp->link;
        
    }
}

void Insert() {
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    int d;

    printf("Enter an integer to insert \n");
    scanf("%d", &d);

    ptr->data = d;
    ptr->link = NULL;
    if(start == NULL) {
        start = ptr;
    }else {
        struct node* temp;
        temp = start;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = ptr;
    }
   
    Display();
    printf("\n------");
    isSplited = 0;
    
}

void Display() {
    printf("\n");
    struct node* temp;
    temp = start;
    while(temp != NULL) {
        
        printf("%d ", temp->data);
        temp = temp->link;
        
    }
}
void Delete() {
    isSplited = 0;
    int element;
    printf("Enter the element that you want to delete\n");
    scanf("%d", &element);
    struct node* temp, *prev;
    int found = 0;
    temp = start;
    if(temp != NULL && temp->data == element ) {
        start = temp->link;
        printf("Element deleted is %d", temp->data);
        free(temp);
        
        return;
    }
    
    
    while(temp != NULL) {
        if(temp->data == element) {
            found = 1;
            
            prev->link = temp->link;
            printf("Element deleted is %d", temp->data);
            
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->link;
    }
    
    if(found == 0) {
        printf("Element not found in the list\n");
    }
}
