#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	int data;
	struct node*lchild,*rchild;
}bitree;
bitree *Create_Tree()
{
	bitree *root;
	int ch;
	    scanf("%d", &ch);
		root = (bitree *)malloc(sizeof(bitree));
		root->data = ch;
		root->lchild = Create_Tree();//存在左孩子节点，递归调用本函数，使得左孩子节点先被赋值
		root->rchild = Create_Tree();
		return root;
}
void print(bitree *t)
{
	if(t==NULL)
	  printf("error");
	else
	{
	  printf("%d ",t->data);
	  print(t->lchild);
	  print(t->rchild);
}
}
int main()
{
	int m;
	scanf("%d",&m);
	bitree *l;
	l=Create_Tree();
	print(l);
}
