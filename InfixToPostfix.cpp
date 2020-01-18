/*********************************************************************************************************************
     **
     **  Infix to postfix conversion in C++ using stack and linked list
     **  Input Postfix expression must be in a desired format. 
     **  Operands and operator, both must be single character.
     **  Only '+'  ,  '-'  , '*', '/'  operators are expected. 
     
     **  Written By:    Akash Vishwas Londhe
     **
*********************************************************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	
	char c;
	struct node *next;
	
}NODE;

NODE *head;

void init()
{

	head=(NODE *)malloc(sizeof(NODE));
	head=NULL;

}

bool isEmpty()
{
	
	if(head==NULL)
		return true;
	return false;
	
}

void push(char c)
{
	
	NODE *a=(NODE *)malloc(sizeof(NODE));
	
	if(head==NULL)
		head=a;
	else
	{
		a->next=head;
		head=a;
	}	
	
	head->c=c;
	
}

void pop()
{
	
	if(head==NULL)
		return;
	else
		head=head->next;
		
}

char top()
{
	
	if(isEmpty())
	return -1;

	return head->c;
	
}

bool isOperator(char c)
{
	
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		return false;
	}
	
}

int precedance(char c)
{
	
	switch(c)
	{
		case '+': return 2;
		case '-':return 2;
		case '*':return 1;
		case '/':return 1;
		
	}
	
}

bool isHighPrecedance(char c1,char c2)
{

	if(isEmpty())
	return false;
	if(precedance(c1)<precedance(c2))
		return false;
	return true ;
	
}

char * infixToPostfix(char *exp)
{

	int i=0,j=0;
	char *res=(char *)malloc(sizeof(char)*strlen(exp));

	init();

	for(i=0;i<strlen(exp);i++)
	{
	
		if(!isOperator(exp[i]))
		{
		
			res[j++]=exp[i];
	
		}
		else
		{
			
			while(!isEmpty() && isHighPrecedance(exp[i],top()))
			{
			  
				res[j++]=top();
			
				pop();	
				
			}
			
			push(exp[i]);
			
		}
		
	}
	
	while(!isEmpty())
	{
		
		res[j++]=top();
		pop();
		
	}

	return res;
	
}


int main()
{
	char a[]="a+b*c-d/e";

	printf("%s",infixToPostfix(a));
	
	return 0;
	
}
