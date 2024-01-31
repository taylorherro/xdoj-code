#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct node {
	int data;
	struct node* lchild, * rchild;
}bitree;
bitree* insert(bitree*t,bitree *s)
{
	node* p, *f;
	p = t;
	f = NULL;
	while (p != NULL) {
		f = p;
		if (s->data == p->data)
			return t;
		else if (s->data < p->data)
			p = p->lchild;
		else {
			p = p->rchild;
		}
	}
	if (t==NULL)
		return s;
	else if (f->data > s->data)
		f->lchild = s;
	else {
		f->rchild = s;
	}
	return t;
}
bitree *create(int n)
{
	node* s, * t;
	t = NULL;
	int data;
	for (int i = 0; i < n; i++)
	{
		s = (bitree*)malloc(sizeof(bitree));
		scanf("%d", &data);
		s->data = data;
		s->lchild = NULL;
		s->rchild = NULL;
		t = insert(t, s);
	}
	return t;
}
void order(bitree* t)
{
	if (t != NULL) {
		printf("%d ", t->data);
		order(t->lchild);
		order(t->rchild);
	}
}
void reverseorder(bitree* t)
{
	if (t != NULL) {
		reverseorder(t->lchild);
		reverseorder(t->rchild);
		printf("%d ", t->data);
	}
}
void inorder(bitree* t)
{
	if (t != NULL)
	{
		inorder(t->lchild);
		printf("%d ", t->data);
		inorder(t->rchild);
	}
}
int main() {
	int sum;
	scanf("%d", &sum);
	bitree* t = create(sum);
	order(t);
	printf("\n");
	inorder(t);
	printf("\n");
	reverseorder(t);
}
//while (p != NULL)
//{
//	f = p;
//	if (== )
//		retrun t;
//}
//if (== NULL)
//return s;
//
//
//
//f ==
//f =
//return t;
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <malloc.h>
//
//typedef struct node {
//	int data;
//	struct node* lchild, * rchild;
//} node;
//
//
//node* insert(node* t, node* s) {
//	node* p, * f;
//	p = t;
//	while (p != NULL) {
//		f = p;
//		if (s->data == p->data)
//			return t;
//		if (s->data < p->data)
//			p = p->lchild;
//		else
//			p = p->rchild;
//	}
//	if (t == NULL)
//		return s;
//	if (s->data > f->data)
//		f->rchild = s;
//	else
//		f->lchild = s;
//	return t;
//}
//
//node* creat(int num) {
//	node* t, * s;
//	int data;
//	t = NULL;
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &data);
//		s = (node*)malloc(sizeof(node));
//		s->lchild = NULL;
//		s->rchild = NULL;
//		s->data = data;
//		t = insert(t, s);
//	}
//	return t;
//}
//
//void order(node* p) {
//	if (p != NULL) {
//		order(p->lchild);
//		printf("%d ", p->data);
//		order(p->rchild);
//	}
//}
//
//int main() {
//	int num;
//	scanf("%d", &num);
//	node* tree = creat(num);
//	order(tree);
//	return 0;
//}