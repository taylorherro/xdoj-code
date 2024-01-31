#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* lchild, * rchild;
} node;


node* insert(node* t, node* s) {
	node* p, * f;
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
		order(p->lchild);
		printf("%d ", p->data);
		order(p->rchild);
	}
}

int main() {
	int num;
	scanf("%d", &num);
	node* tree = creat(num);
	order(tree);
	return 0;
}






















