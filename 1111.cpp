#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* lchild, * rchild;
} node;
node* insert(node* t, node* s) {
	node* p;
	node *f;
	p = t;
	while (p != NULL) {
		f = p;
		if (s->data == p->data)
			return t;
		if (s->data < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (t == NULL)
		return s;
	if (s->data > f->data)
		f->rchild = s;
	else
		f->lchild = s;
	return t;
}

node* creat(int num) {
	node* t, * s;
	int data;
	t = NULL;
	for (int i = 0; i < num; i++) {
		scanf("%d", &data);
		s = (node*)malloc(sizeof(node));
		s->lchild = NULL;
		s->rchild = NULL;
		s->data = data;
		t = insert(t, s);
	}
	return t;
}
void order(node* p) {
	if (p != NULL) {
		printf("%d ", p->data);
		order(p->lchild);
		order(p->rchild);
	}
}
void reverseorder(node* p) {
	if (p != NULL) {
		reverseorder(p->lchild);
		reverseorder(p->rchild);
		printf("%d ", p->data);
	}
}

int main() {
	int num;
	scanf("%d", &num);
	node* tree = creat(num);
	printf("\n");
	return 0;
}





















