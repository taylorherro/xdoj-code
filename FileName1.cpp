#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}linklist;
linklist* creat(int n)
{
	linklist* head, *s,* r;
	int a;
	head = (linklist*)malloc(sizeof(linklist)); 
	r = head;
	for (int i = 0; i < n; i++)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &a);
		s->data = a;
		r ->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}
void sort(linklist* head, int m)
{
	linklist *r,*s,*p;
	int n1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &n1);
		s = (linklist*)malloc(sizeof(linklist));
		s->data = n1;
		p = head;
		r = p->next;
		while (r != NULL)
		{
			if (s->data > r->data)
			{
				p = r;
				r = r->next;
			}
			else if(s->data<r->data)
			{
				p->next = s;
				s->next = r;
				break;
			}
			else if(s->data ==r->data)
			{
				break;
			}

		}
		if (r == NULL)
		{
			p->next = s;
			s->next = r;
		}
	}
}
void  print(linklist* head)
{
	linklist* r, * p;
	p = head;
	r = p->next;
	while (r->next != NULL)
	{
		printf("%d ", r->data);
		r = r->next;
	}
	printf("%d", r->data);
}
int main()
{
	int n, m;
	linklist* l;
	scanf("%d%d",& n, &m);
	l=creat(n);
	sort(l,m);
	print(l);
}