#include<stdio.h>
#include<stdlib.h>
void Insert();
void Delete();
void display();
void Revdisplay();
struct node
{
	int info;
	struct node *link;
};
struct node *start;
int main()
{
	int n;
	while(1)
	{
		printf("\n 1.Insert");
		printf("\n 2.Delete");
		printf("\n 3.Revdisplay");
		printf("\n 4.Exit");
		scanf("%d",&n);
		if(n==1)
			Insert();
		else if(n==2)
			Delete();
		else if(n==3)
			Revdisplay();
		else
			exit(0);
	}
	return 0;
}

void Insert()
{
	int i;
	struct node *test,*test1;
	test=malloc(sizeof(struct node));
	printf("\n enter the data");
	scanf("%d",&i);
	test->info=i;
	test->link=NULL;
	if(start==NULL)
	{
		start=test;
	}
	else
	{
		test1=start;
		while(test1->link!=NULL)
		{
			test1=test1->link;
		}
		test1->link=test;
	}
	display();
}
void display()
{
	struct node *test;
	test=start;
	while(test!=NULL)
	{
		printf("\n %d",test->info);
		test=test->link;
	}
}

void Revdisplay()
{
	struct node *test,*test1,*new,*new1;
	new=start;
	while(new->link!=NULL)
	{
		new=new->link;
	}
	while(new!=start)
	{
		test=new;
		printf("\n %d",test->info);
		test1=start;
		while(test1->link!=test)
		{
			test1=test1->link;
		}
		test1->link=new;
		new=test1;
	}
	printf("\n %d",start->info);
}


void Delete()
{
}
