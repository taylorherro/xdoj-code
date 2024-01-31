
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
	int data;
	struct node* next;
}linklist;

linklist* Creat(int N)
{
	int a, i;
	linklist* head, * r, * s;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a);
		s = (linklist*)malloc(sizeof(linklist));
		s->data = a;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}        //尾插法创建带头结点的单链表

void Insert(linklist* head, int x)
{
	linklist* s, * r, * p;
	r = head->next;
	p = head;
	s = (linklist*)malloc(sizeof(linklist));
	s->data = x;
	while (r != NULL)
	{
		if (s->data > r->data)
		{
			p = r;
			r = r->next;
		}
		else
		{
			p->next = s;
			s->next = r;
			break;
		}
	}
	if (r == NULL)
	{
		p->next = s;
		s->next = r;
	}
}     //插入来晚小朋友的身高

void Print(linklist* head)
{
	linklist* r;
	r = head->next;
	while (r->next != NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
	printf("%d\n", r->data);
}       //打印链表

int main()
{
	linklist *L;
	int N, M;
	scanf("%d %d", &N, &M);
	L = Creat(N);
	Insert(L, M);
	Print(L);
	return 0;
}