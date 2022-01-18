#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void post(char[]);
void pre(char[]);
void push(char);
char pop();
int getPrecedence(char);
int GetAssociativity(char);
char output[15], stack[10],*top;
int j=0;
int main()
{
	char array[15];
	int n;
	while(1)
	{
	    top=NULL;
	    j=0;
		printf("\n 1. POST");
		printf("\n 2. PRE");
		printf("\n 3. EXIT");
		scanf("%d",&n);
		printf("\n Enter the expression ");
		scanf("%s",array);
		if(n==1)
			post(array);
		else if(n==2)
			pre(array);
		else
			exit(0);
	}
	return 0;
}

void post(char array[])
{
	int i=0,x,n1;
	char c,ch;
	 c=array[i];
	while(c!='\0')
	{
	   
		x=isalnum(c);
		if(x==0)
		{
			n1=getPrecedence(c);
			if(n1==5)
			{ 
				push(c);
				
			}
			else if(n1==4)
			{
			   // printf("%c top is \n", *top);
			   // printf("\n char is %c ", stack[0]);
			    ch=pop();
			    //printf("top is %c \n", *top);
			    
				while(ch != '(')
				{
				   // printf("\n poping stack is %s ",stack);
					output[j]=ch;
					j++;
					ch=pop();
				}
			}
			else if(n1==3)
			{
                push(c);
			}
			else if(n1==2)  
			{ 
			  if(top == NULL) 
			    push(c);
			  else{
			      if(2 > getPrecedence(*top)){
			           push(c);
			      }else if(2 <= getPrecedence(*top) ) {
			           while(2 <= getPrecedence(*top)  && *top != '(') {
			                ch=pop();
			                output[j]=ch;
			                j++;
			           }
			           push(c);
			           
			       }
			       
			  }  
			    
			  
			}
			else if(n1==1)  // a+b+c = abc+
			{
			    if(top == NULL) 
			    push(c);
			  else{
			      if( 1 > getPrecedence(*top)){
			        push(c);
			    }else if(1 <= getPrecedence(*top)) {
			           while(1 <= getPrecedence(*top)  && *top != '(') {
			              // printf("bug times called");
			             ch=pop();
			             output[j]=ch;
			             j++;
			           }
			           push(c);
			       }
			       
			  }
			    
			}
		}
		else
		{
			output[j]=c;
			j++;
			
		}
		
		i++;
		c=array[i];
	}
	while(top!=&stack[-1] && top != NULL)
	{
	   // printf("\n stack is %s",stack);
		c=pop();
		output[j]=c;
		j++;
		
	}
	printf("\n PostFix Expression is: %s",output);
}

void push(char c)
{
	if(top==NULL)
	{
		top=&stack[0];
		*top=c;
	}
	else
	{
		if(top==&stack[10])
			printf("\n OVERFLOW");
		else
		{
			top++;
			*top=c;
		}
	}
}

char pop()
{
    //printf("\npop called for %c\n", *top);
	char c;
	c = *top;
	top--;
	return c;
}

int GetAssociativity(char c){
    if(c =='*') return 4;
    else if(c =='/') return 3;
    else if(c =='+') return 2;
    else if(c== '-') return 1;
}

int getPrecedence(char c)
{
	if(c=='(')
		return 5;
	else if(c==')')
		return 4;
	else if(c=='^')
		return 3;
	else if(c=='/' | c=='*')
		return 2;
	else if(c=='-'|c=='+')
		return 1;
			
}
void pre(char array[])
{
    char temp;
   int jk,length;
   length=strlen(array)-1;
   for(jk=0;jk<strlen(array)/2;jk++){
      temp=array[jk];
      array[jk]=array[length];
      array[length--]=temp;
   }
    //printf("%s\n", array);
    
    int i=0,x,n1;
	char c,ch;
	c=array[i];
//	printf("%s", array);
	while(c!='\0')
	{
		x=isalnum(c);
		if(x==0)
		{
			n1=getPrecedence(c);
			if(n1==5)
			{ 
				push(c);
				
			}
			else if(n1==4)
			{
			   // printf("%c top is \n", *top);
			   // printf("\n char is %c ", stack[0]);
			    ch=pop();
			    //printf("top is %c \n", *top);
			    
				while(ch != '(')
				{
				   // printf("\n poping stack is %s ",stack);
					output[j]=ch;
					j++;
					ch=pop();
				}
			}
			else if(n1==3)
			{
                push(c);
			}
			else if(n1==2)  
			{ 
			  if(top == NULL) 
			    push(c);
			  else{
			      if(2 > getPrecedence(*top)){
			           push(c);
			      }else if(2 <= getPrecedence(*top) ) {
			           while(2 <= getPrecedence(*top)  && *top != '(') {
			                ch=pop();
			                output[j]=ch;
			                j++;
			           }
			           push(c);
			           
			       }
			       
			  }  
			    
			  
			}
			else if(n1==1)  // a+b+c = abc+
			{
			    if(top == NULL) 
			    push(c);
			  else{
			      if( 1 > getPrecedence(*top)){
			        push(c);
			    }else if(1 <= getPrecedence(*top)) {
			           while(1 <= getPrecedence(*top)  && *top != '(') {
			              // printf("bug times called");
			             ch=pop();
			             output[j]=ch;
			             j++;
			           }
			           push(c);
			       }
			       
			  }
			    
			}
		}
		else
		{
			output[j]=c;
			j++;
			
		}
		
		i++;
		c=array[i];
	}
	while(top!=&stack[-1] && top != NULL)
	{
	   // printf("\n stack is %s",stack);
		c=pop();
		output[j]=c;
		j++;
		
	}
	

   
   length=strlen(output)-1;
   for(jk=0;jk<strlen(output)/2;jk++){
      temp=output[jk];
      output[jk]=output[length];
      output[length--]=temp;
   }
   
	printf("\n PreFix Expression is: %s",output);
	
    
}



