//DFA to accept 01 substring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char s[20],state[3] = "q0",c;
	int i = 0;
	printf("\nGet string : ");
	gets(s);
	while(i < strlen(s))
	{
		c = s[i];
		printf("\n%s ",state);
		printf("%c",c);
		if(strcmp(state,"q0") == 0)
		{
			if(c == '0')
			{
				strcpy(state,"q1");
			}
		}
		else if(strcmp(state,"q1") == 0)
		{
			if(c == '1')
			{
				strcpy(state,"q2");
			}
		}
		else if(strcmp(state,"q2") == 0)
		{
			break;
		}
		printf(" -> %s",state);
		i++;
	}
	if(strcmp(state,"q2") == 0)
	{
		printf("\nString is accepted");
		return;
	}
	printf("\nString is not accepted");
}