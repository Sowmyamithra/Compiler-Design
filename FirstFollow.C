//First and Follow
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char prod[10][10];
char ans[100],stk[100];
int ip = 0,tos = -1,i,j,flag,k;
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
void first(char c)
{
	tos = -1;
	ip = 0;
	push(c);
	while(tos != -1)
	{
		c = stk[tos];
		pop();
		if(islower(c))
		{
			ans[ip++] = c;
		}
		else if(isupper(c))
		{
			for(i = 0;i < 6;i++)
			{
				if(prod[i][0] == c)
				{
					for(j = strlen(prod[i]) - 1;j >= 2;j--)
					{
						push(prod[i][j]);
					}
				}
			}
		}
		else if(c == '$')
		{
			if(tos == -1)
			{
				ans[ip++] = '$';
			}
		}
	}
}
void follow(char c)
{
	int i,j,k;
	if(c == 'S')
	{
		printf("\n$");
	}
	for(i = 0;i < 6;i++)
	{
		j = 2;
		while(j < strlen(prod[i]))
		{
			if(prod[i][j] == c)
			{
				if(j == strlen(prod[i]) - 1)
				{
					follow(prod[i][0]);
				}
				else
				{
					while(j < strlen(prod[i]))
					{
						j = j + 1;
						if(islower(prod[i][j]))
						{
							printf("\n%c",prod[i][j]);
							break;
						}
						first(prod[i][j]);
						flag = 1;
						for(k = 0;k < ip;k++)
						{
							if(ans[k] != '$')
							{
								printf("\n%c",ans[k]);
							}
							else
							{
								flag = 0;
							}
						}
						if(flag == 0)
						{
							if(j == strlen(prod[i]) - 1)
							{
								follow(prod[i][0]);
							}
							else
							{
								continue;
							}
						}
						else
						{
							break;
						}
					}
				}
			}
			j++;
		}
	}
}
void main()
{
	char c;
	int i;
	printf("\nGet productions : \n");
	for(i = 0;i < 6;i++)
	{
		gets(prod[i]);
	}
	printf("\nEnter the symbol to find first and follow : ");
	scanf("%c",&c);
	first(c);
	printf("\nFirst of %c : ",c);
	for(i = 0;i < ip;i++)
	{
		printf("\n %c",ans[i]);
	}
	printf("\nFollow of %c : ",c);
	follow(c);
}