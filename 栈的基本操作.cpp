#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int count = 0;
//ջ�Ķ���
typedef struct {
	int data[MAX];
	int top;
}SeqStack;
//ջ�ĳ�ʼ��
void InitStack(SeqStack* s) {
	s->top = -1;
}
//��ջ
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
//�ͷ���ջ
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