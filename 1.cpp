#include<bits/stdc++.h>
typedef struct node {
	int data;
	struct node* next;
}linklist;
linklist* creat(int n)
{
	linklist* head, * r, * s;
	r = head;
	int a;
	for (int i = 0; i < n; i++)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &a);
		s->data = a;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}
void sort(linklist* head)
{
	linklist* p, * r, * s;
	s= head;
	p= s->next;
	r= p->next;
	while (p->next != NULL)
	{
		p->next = r->next;
		r->next = s->next;
		s->next = r;
		r = p->next;
	}
}
void print(linklist *head)
{
	linklist* p, * r;
	p = head;
	r = p->next;
	while (r!= NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	linklist* l;
	l = creat(n);
	sort(l);
	print(l);
}
