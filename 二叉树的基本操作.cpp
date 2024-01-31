#include<bits/stdc++.h>
typedef struct node {
	char data;
	struct node* left, * right;
}*bitree;
void create(bitree& t)
{
	char n;
	scanf("%c", &n);
	if (n == '#')
		t = NULL;
	else {
		t = (bitree)malloc(sizeof(bitree));
		t->data = n;
		t->left = NULL;
		t->right = NULL;
		create(t->left);
		create(t->right);
	}
}
void print(bitree& t)
{
	if (t == NULL)
		return;
		print(t->left);
		printf("%c ", t->data);
		print(t->right);	
}
int main()
{
	bitree l;
	create(l);
	print(l);
}