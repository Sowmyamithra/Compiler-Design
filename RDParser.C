//Recursive Descent parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ip;
char exp[20];
void S();
void A();
void B();
void main()
{
	printf("\nGet string : ");
	gets(exp);
	S();
	if(exp[ip] == '$')
	{
		printf("\nValid");
		return;
	}
	printf("\nInvalid");
}
void S()
{
	A();
	B();
}
void A()
{
	if(exp[ip] == 'a')
	{
		ip++;
	}
}
void B()
{
	if(exp[ip] == 'b')
	{
		ip++;
	}
}