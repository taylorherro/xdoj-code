#include<bits/stdc++.h>
typedef struct node {
	int data;
	struct node* next;
}linklist;
linklist* create(int n)
{
	linklist* head;
	head = (linklist*)malloc(sizeof(linklist));
	linklist* r, * s=NULL;
	r = head;
	for (int i = 0; i < n; i++)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &s->data);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}
void rreverse(linklist* head)
{
	linklist* beg, * end,*r;
	r = head;
	beg = r;
	end = r->next;
	while (end != NULL)
	{
		beg = end->next;
		end->next = r;
		r = end;
		end = beg->next;
	}
}
void print(linklist* head)
{
	linklist* r;
	r = head->next;
	while (r != NULL)
	{
		printf("%d", r->data);
		r = r->next;
	}
}
//void  reverse(linklist* head) {
//	linklist* p, * q;
//	p = head->next;
//	head->next = NULL;
//	while (p != NULL) {
//		q = p;
//		p = p->next;
//		q->next = head->next;
//		head->next = q;
//	}
//}
void reverse(linklist* head)
{
	linklist* p, * q;
	p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	linklist* l;
	l = create(n);
	reverse(l);
	print(l);
}