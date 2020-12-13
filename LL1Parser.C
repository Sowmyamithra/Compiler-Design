//LL1 Parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stk[100];
int tos = -1;
void push(char c)
{
	if(tos < 99)
	{
		stk[++tos] = c;
	}
}
void pop()
{
	if(tos != -1)
	{
		tos--;
	}
}
void main()
{
	char exp[20],X,a,str[10];
	int i = 0,j;
	printf("\nGet expression : ");
	gets(exp);
	push('$');
	push('E');
	while(i < strlen(exp))
	{
		a = exp[i];
		X = stk[tos];
		if(X == a && a == '$')
		{
			printf("Valid Expression");
			return;
		}
		else if(X == a &&  a != '$')
		{
			pop();
			i++;
		}
		else if(X != a)
		{
			strcpy(str,"");
			printf("\nGet action (%c , %c) : ",X,a);
			gets(str);
			if(strlen(str) != 0)
			{
				if(strcmp(str,"e") == 0)
				{
					pop();
				}
				else
				{
					pop();
					for(j = strlen(str) - 1;j >= 0;j--)
					{
						push(str[j]);
					}
				}
			}
			else
			{
				printf("\nInvalid Expression");
				return;
			}
		}
		else
		{
			printf("\nInvalid Expression");
			return;
		}
	}
}