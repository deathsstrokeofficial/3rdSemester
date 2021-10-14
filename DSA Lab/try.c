#include<stdio.h>
#include<stdlib.h>

struct test Qinsert(int *,struct test);
void display(int *, struct test);
struct test Qdelete(int *,struct test);
struct test
{
	int *front,*rear;
};
int main()
{
	int arr[10],n;
	struct test dsa;
	printf("\n AT MAX 10 ELEMENT IS ALLOWED");
	dsa.front=NULL;
	dsa.rear=NULL;
	while(1)
	{
	    printf("\nChoose a option according to your choice.");
		printf("\n 1. QUEUE INSERT");
		printf("\n 2. QUEUE DELETE");
		printf("\n 3. EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		if(n==1)
			dsa=Qinsert(arr,dsa);
		else if(n==2)
            dsa=Qdelete(arr,dsa);
		else
			exit(0);
	}
	return 0;
}
struct test Qinsert(int *arr1, struct test dsa)
{
	int i;
	printf("\n Enter the data you want to insert:");
	scanf("%d",&i);
	if(dsa.front==NULL && dsa.rear==NULL)
	{
		dsa.rear=&arr1[0];
		*dsa.rear=i;
		dsa.front=dsa.rear;
	}
	else
	{
		if(dsa.rear==&arr1[9])
		{
			printf("\n OVERFLOW");
		}
		else
		{
			dsa.rear++;
			*dsa.rear=i;
		}
	}
	display(arr1,dsa);
	return dsa;
}
struct test Qdelete(int *arr2,struct test dsa)
{
    if(dsa.front>dsa.rear || dsa.rear==NULL&dsa.front==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        dsa.front++;
    }
    display(arr2,dsa);
    return dsa;
}
void display(int *arr3,struct test dsa)
{
	int *i;
	for(i=dsa.front;i<=dsa.rear;i++)
		printf("\n %d",*i);
}
