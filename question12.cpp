#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxsize 1000
typedef struct {
	int data[maxsize];
	int top;
}sqstack;
bool pushstack(sqstack *s,int x)
{
	if(s->top==maxsize-1)
	{ 
		return false;
	}
	else
	{
		s->data[++s->top] = x;
		return true;
	}
}
bool popstack(sqstack* s, int x)
{
	if (s->top == -1)
	{
		return false;
	}
	else {
		s->data[s->top--] = x;
		return x;
	}
}