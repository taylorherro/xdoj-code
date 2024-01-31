#include<bits/stdc++.h>
#define maxsize 100;
int count = 0;
typedef struct {
	char data[100];
	int top;
}sqstack;
void initstack(sqstack* s)
{
	s->top = -1;
}
void pushstack(sqstack* s, char a)
{
	if (s->top == 99)
	{
		printf("full");
		return;
	}
	s->top++;
	s->data[s->top] = a;
}
char gettop(sqstack* s)
{
	if (s->top == -1)
	{
		printf("empty");
		return 0;
	}
	return s->data[s->top];
}
void popstack(sqstack* s)
{
	if (s->top == -1)
	{
		printf("empty");
		return;
	}
	s->top--;
}
int main()
{
	sqstack *ss=NULL;
	initstack(ss);
	char temp;
	char arr[100];
	gets_s(arr);
	for (int i = 0; i < strlen(arr); i++)
	{
		switch (arr[i])
		{
		case'(':
			pushstack(ss, arr[i]);
			break;
		case'[':
			pushstack(ss, arr[i]);
			break;
		case'{':
			pushstack(ss, arr[i]);
			break;
		case')':
			temp = gettop(ss);
			if (temp == '(')
			{
				popstack(ss);
			}
			else
				count++;
			break;
		case']':
			temp = gettop(ss);
			if (temp == '[')
			{
				popstack(ss);
			}
			else
				count++;
			break;
		case'}':
			temp = gettop(ss);
			if (temp == '{')
			{
				popstack(ss);
			}
			else
				count++;
			break;
		}
	}
	if (count == 0 && ss->top == -1)
	{
		printf("success");
	}
	else
		printf("false");
}