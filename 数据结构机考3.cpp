#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node *lchild, *rchild;
} node;

node *insert(node *t,node *s)
{
	node *p,*f;
	p=t;
    if(t==NULL)
    return s;
    while(p!=NULL)
    {
    	f=p;
    	if(s->data==p->data)
    	return t;
    	if(s->data>p->data)
    	p=p->rchild;
    	if(s->data<p->data)
    	p=p->lchild;
	}
	if(s->data>f->data)
	f->rchild=s;
	else{
		f->lchild=s;
	}
	return t;
}
node *create(int n)
{
	int data;
	node *s,*t=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		s=(node*)malloc(sizeof(node));
		s->data=data;
		s->lchild=NULL;
		s->rchild=NULL;
		t=insert(t,s);
	}
	return t;
}
void order(node *p) {
	if (p != NULL) {
		printf("%d ", p->data);
		order(p->lchild);
		order(p->rchild);
	}
}
void reverseorder(node *p) {
	if (p != NULL) {
		reverseorder(p->lchild);
		reverseorder(p->rchild);
		printf("%d ",p->data);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	node *tree = create(n);
	order(tree);
	printf("\n");
	reverseorder(tree);
	return 0;
}
