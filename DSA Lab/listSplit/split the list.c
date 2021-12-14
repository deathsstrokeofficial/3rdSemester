#include <stdio.h>
#include <stdlib.h>
void Display();
void Insert();
void Delete();
struct node;
void split(struct node**, struct node**);
void DisplayLeftPart(struct node*);
void DisplayRightPart(struct node*);

struct node {
    int data;
    struct node* link;
};

struct node* startNode;
int isSplited = 0;



int main() {
    struct node* leftSplit;
    struct node* rightSplit;
    
    int n;
    
    printf("Enter Your Choise\n");
    while(1) {
        printf("\n1: To insert data\n");
        printf("2: To display data\n");
        printf("3: To Delete data\n");
        printf("4: To Split the list into two \n");
        printf("5: To Display Splited Left part \n");
        printf("6: To Display Splited Right part \n");
        printf("7: To Exit ");
        
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
            case 5: DisplayLeftPart(leftSplit);
            break;
            case 6: DisplayRightPart(rightSplit);
            break;
            default: printf("Invalid Option\n");
        }
    }
    return 0;
}

void split(struct node** left, struct node** right) { //  {2, 3, 5, 7, 11} = {2, 3, 5} and {7,11}.
    if(isSplited == 1){
        free(*right);
       
    }
    
    if(startNode == NULL) {
        printf("Can't Split an empty list \n");
        isSplited =0;
        return;
    }
    if(startNode->link == NULL) {
        isSplited =0;
        printf("Minimum two elements required to split the list");
        return;
    }
    *left = startNode;
    
    int noOfNodes = 0;
    struct node* temp;
    temp=startNode;
    
    while(temp!= NULL) {
        noOfNodes++;
        temp=temp->link;
    }
    
    int add = 0;
    if(noOfNodes % 2 !=0) {
        add = 1;
    }
    
    struct node* trav;
    trav = startNode;
    int i=1;
        
    while(trav!= NULL && i != (noOfNodes/2) + add) { //  {2, 3, 5, 7, 11} = {2, 3, 5} and {7,11}.
        i++;
        trav=trav->link;
    }
        
    *right = trav->link;
    trav->link = NULL;
    
    printf("Split Successful \n");
    isSplited = 1;
    
}

void DisplayLeftPart(struct node* left) {
    if(startNode == NULL){
        printf("Can't display an empty list \n");
        return;
    }
    if(isSplited == 0) {
         printf("List is not Splited \n");
        return;
    }
   
    struct node* temp;
    temp=left;
    while(temp!= NULL) {
        
        printf("%d ", temp->data);
        temp=temp->link;
        
    }
}

void DisplayRightPart(struct node* right) {
     if(startNode == NULL) {
        printf("Can't display an empty list \n");
        return;
    }
    if(isSplited == 0) {
        printf("List is not Splited \n");
        return;
    }
    
    struct node* temp;
    temp=right;
    while(temp!= NULL) {
        
        printf("%d ", temp->data);
        temp=temp->link;
        
    }
}

void Insert() {
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
     printf("Enter an integer to insert \n");
    int d;
    scanf("%d", &d);
    ptr->data=d;
    ptr->link=NULL;
    if(startNode ==NULL) {
        startNode= ptr;
    }else{
        struct node* temp;
        temp=startNode;
        while(temp->link != NULL) {
            temp=temp->link;
        }
        temp->link=ptr;
    }
   
    Display();
    printf("\n------");
    isSplited = 0;
    
}

void Display() {
    printf("\n");
    struct node* temp;
    temp=startNode;
    while(temp!= NULL) {
        
        printf("%d ", temp->data);
        temp=temp->link;
        
    }
}
void Delete() {
    isSplited =0;
    int element;
    printf("Enter the element that you want to delete\n");
    scanf("%d", &element);
    struct node* temp, *prev;
    int found = 0;
    temp=startNode;
    if(temp != NULL && temp->data == element ) {
        startNode=temp->link;
        printf("Element deleted is %d", temp->data);
        free(temp);
        
        return;
    }
    
    
    while(temp!=NULL) {
        if(temp->data == element) {
            found=1;
            
            prev->link=temp->link;
            printf("Element deleted is %d", temp->data);
            
            free(temp);
            break;
        }
        prev = temp;
        temp=temp->link;
    }
    
    if(found == 0) {
        printf("Element not found in the list\n");
    }
}
