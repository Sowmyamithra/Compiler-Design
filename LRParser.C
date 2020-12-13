//LR Parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stk[100][10];
int tos = -1;
void push(char *s)
{
	if(tos < 99)
	{
		strcpy(stk[++tos],s);
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
	char exp[20],a,X[5],str[10],temp[2];
	int i = 0,j,len;
	printf("\nGet Expression : ");
	gets(exp);
	push("$");
	push("0");
	while(i < strlen(exp))
	{
		strcpy(str,"");
		a = exp[i];
		strcpy(X,stk[tos]);
		printf("\nGet action (%s , %c)",X,a);
		scanf("%s",str);
		if(strcmp(str,"r0") == 0)
		{
			printf("\nValid Expression");
			return;
		}
		if(strcmp(str,"e") == 0)
		{
			printf("\nInvalid Expression");
			return;
		}
		if(str[0] == 's')
		{
			strcpy(temp,"");
			temp[0] = a;
			temp[1] = '\0';
			push(temp);
			strcpy(temp,"");
			for(j = 1;j < strlen(str);j++)
			{
				temp[j-1] = str[j];
			}
			temp[j-1] = '\0';
			push(temp);
			i++;
		}
		else if(str[0] == 'r')
		{
			strcpy(temp,"");
			for(j = 1;j < strlen(str);j++)
			{
				temp[j-1] = str[j];
			}
			temp[j-1] = '\0';
			printf("\nGet length for %s : ",temp);
			scanf("%d",&len);
			for(j = 0;j < len;j++)
			{
				pop();
				pop();
			}
			strcpy(X,stk[tos]);
			printf("\nGet head for %s : ",temp);
			scanf("%s",str);
			push(str);
			printf("\nGet action (%s , %s) : ",X,str);
			scanf("%s",str);
			push(str);
		}
	}
}