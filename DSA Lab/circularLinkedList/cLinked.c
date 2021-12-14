#include<stdio.h>
#include<stdlib.h>

void INSERT();
void delete();
void display();

struct node
{
	int info;
	struct node *link;
};

struct node *start;

int main()
{
	int n;
	start=NULL;

	while(1)
	{
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. EXIT\n");
		scanf("%d",&n);
		if(n==1)
			INSERT();
		else if(n==2)
			delete();
		else
			exit(0);
	}
	return 0;
}

void INSERT()
{
	struct node *temp,*next;
	int i;

	temp=malloc(sizeof(struct node));
	printf("\n enter the number: ");
	scanf("%d",&i);

	temp->info=i;
	temp->link=NULL;

	if(start==NULL)
	{
		start=temp;
		start->link=start;
	}
	else
	{
		next=start;

		while(next->link!=start)
		{
			next=next->link;
		}
		next->link=temp;
		temp->link=start;
	}
	display();
}

void display()
{
	struct node *tmp;
	tmp=start;

	while(tmp->link!=start)
	{
		printf("\n %d",tmp->info);
		tmp=tmp->link;
	}
	printf("\n %d",tmp->info);
}

void delete ()
{
    struct node *test;
    test = start;

    if (test == NULL)
    {
        printf("\nUNDERFLOW!");
    }
    else if (start->link == start)
    {
        start = NULL;
    }
    else
    {
        while (test->link->link != start)
        {
            test = test->link;
        }

        test->link = start;
    }
    display();
}