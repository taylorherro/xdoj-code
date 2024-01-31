#include<bits/stdc++.h>
int n;
typedef struct node {
	int data;
	struct node* lchild, * rchild;
}node;
node* insert(node* t, node* s)
{
	node* p, * f=NULL;
	p = t;
	if (t == NULL)
		return s;
	while (p != NULL)
	{
		f = p;
		if (s->data == p->data)
			return t;
		if (s->data > p->data)
			p = p->rchild;
		else
			p = p->lchild;
	}
	if (s->data < f->data)
		f->lchild = s;
	else
		f->rchild = s;
	return t;
}
node* create(int n)
{
	node* t = NULL, * s;
	int data;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		s = (node*)malloc(sizeof(node));
		s->data = data;
		s->lchild = NULL;
		s->rchild = NULL;
		t = insert(t, s);
	}
	return t;
}
node* reverse(node* t)
{
	if (t == NULL)
		return NULL;
	node* temp=t->lchild;
	t->lchild = t->rchild;
	t->rchild = temp;
	reverse(t->lchild);
	reverse(t->rchild);
	return t;
}
void order(node* t)
{
	if (t != NULL)
	{
		printf("%d ", t->data);
		order(t->lchild);
		order(t->rchild);
	}
}
int main()
{
	node* t;
	int n;
	scanf("%d", &n);
	t = create(n);
	reverse(t);
	order(t);
}
