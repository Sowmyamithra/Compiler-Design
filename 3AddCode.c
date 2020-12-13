//Three address code generation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char infix[100],postfix[100],helper[100][10],add[100],post[100];
int sp = 48,spx = 0,tos1 = -1,tos2 = -1;

void push(char c)
{
	if(tos1 < 99)
	{
		add[++tos1] = c;
	}
}
char pop()
{
	if(tos1 > -1)
	{
		return add[tos1--];
	}
	return '\0';
}
void push1(char c)
{
    if(tos2 < 99)
    {
        post[++tos2] = c;
    }
}
char pop1()
{
    if(tos2 > -1)
    {
        return post[tos2--];
    }
    return -1;
}
int isOp(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
    {
        return 1;
    }
    return 0;
}
int Prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
void inTopost(char* in)
{
    int pin = 0;
    int i = 0;
    while(i < strlen(in))
    {
        char c = in[i];
        if(isalpha(c))
        {
            postfix[pin++] = c;
        }
        else if(isOp(c) == 1)
        {
            char x = pop1();
            while(isOp(x) == 1 && Prec(x) >= Prec(c))
            {
                postfix[pin++] = x;
                x = pop1();
            }
            push1(x);
            push1(c);
        }
        else if(c == '(')
        {
            push1(c);
        }
        else if(c == ')')
        {
            char x = pop1();
            while(x != '(')
            {
                postfix[pin++] = x;
                x = pop1();
            }
        }
        i++;
    }
    while(tos2 > 0)
    {
        postfix[pin++] = pop1();
    }
    postfix[pin] = '\0';
}

void main()
{
	int i = 0,j = 0;
	printf("\nGet infix exp : \n");
	scanf("%s",infix);
	push('(');
	inTopost(infix);
	printf("\npostfix exp : %s",postfix);
	while(i < strlen(postfix))
	{
		if(isalpha(postfix[i]))
		{
			push(postfix[i]);
		}
		else
		{
			char a = pop();
			char b = pop();
			char s[4];
			s[0] = b;
			s[1] = postfix[i];
			s[2] = a;
			s[3] = '\0';
			push(++sp);
			strcpy(helper[++spx],s);
		}
		i++;
	}
	printf("\n Three address code is : ");
	printf("\n\n____________________________");
	for(j = 1;j <= spx;j++)
	{
		printf("\n%d = %s",j,helper[j]);
	}
}