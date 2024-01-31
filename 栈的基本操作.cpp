#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int count = 0;
//栈的定义
typedef struct {
	int data[MAX];
	int top;
}SeqStack;
//栈的初始化
void InitStack(SeqStack* s) {
	s->top = -1;
}
//入栈
void PushStack(int n,  SeqStack* s)
{
	int data;
	if (s->top == MAX - 1)
	{
		printf("full");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		s->top++;
		s->data[s->top] = data;
	}
}
int GetTop(SeqStack* s,int nn)
{
	for(int i=0;i<nn;i++)
	{
		s->top--;
		return s->data[s->top+1];
	}
}
//释放链栈
void SortStack(SeqStack* S)
{
     
}
int main()
{
	
	SeqStack s;
	int n,nn,data;
	InitStack(&s);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nn);
		PushStack(nn,&s);
		for (int j = 0; j < nn; j++)
			printf("%d ", GetTop(&s,nn));
		printf("\n");
	}
}