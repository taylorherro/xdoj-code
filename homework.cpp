#include<bits/stdc++.h>
typedef struct node {
	int data;
	struct node* pre, * next;
}linklist;
linklist* create(int n)
{
	linklist* head, * p, * s;
	int data;
	head = (linklist*)malloc(sizeof(linklist));
	head->pre = NULL;
	head->next = NULL;
	p = head;
	s = p->next;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		s = (linklist*)malloc(sizeof(linklist));
		s->data = data;
		p->next = s;
		s->pre = p;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void print(linklist* head)
{
	linklist* p = head,*s;
	while (p->next) {
		s = p->next;
		printf("%d", s->data);
		p = p->next;
	}
}
int main()
{
	linklist* l;
	int n;
	scanf("%d", &n);
	l=create(n);
	print(l);
}