#include <stdio.h>
#include <stdlib.h>
//�������Ļ�������
typedef char Elemtype;

typedef struct Bitnode {
	Elemtype data;
	Bitnode* lchild, * rchild;
} Bitnode, * Bitree;

//ǰ��ݹ齨��������
void Creat(Bitree& T) {
	Elemtype n;
	scanf("%c", &n);
	if (n == '#')
		T = NULL;
	else {
		T = (Bitnode*)malloc(sizeof(Bitnode));
		T->data = n;
		T->lchild = NULL;
		T->rchild = NULL;
		Creat(T->lchild);
		Creat(T->rchild);
	}
}
void create(Bitree& t)
{
	char n;
	scanf("%c", &n);
	if (n == '#')
		t= NULL;
	else {
		t = (Bitnode*)malloc(sizeof(Bitnode));
		t->data = n;
		t->lchild = NULL;
		t->rchild = NULL;
		create(t->lchild);
		create(t->rchild);
	}
}
void creat(Bitree& t)
{
	int n;
	scanf("%d", &n);
	if (n == '#')
		t = NULL;

}

//ǰ��ݹ����������
void Inorder(Bitree T) {
	if (T) {
		printf("%c", T->data);
		Inorder(T->lchild);
		Inorder(T->rchild);
	}
}

//ǰ��ǵݹ����������
void Fir_Inorder(Bitree T) {
	Bitree stack[100], p = T;
	int top = 0;
	while (p || top) {
		while (p) {
			stack[top] = p;
			top++;
			printf("%c", p->data);
			p = p->lchild;
		}
		top--;
		p = stack[top];
		p = p->rchild;
	}
}

//����ǵݹ����
void Mid_Inorder(Bitree T) {
	Bitree stack[100], p = T;
	int top = 0;
	while (p || top) {
		while (p) {
			stack[top] = p;
			top++;
			p = p->lchild;
		}
		top--;
		p = stack[top];
		printf("%c", p->data);
		p = p->rchild;
	}
}

//����ǵݹ����
void Las_Inorder(Bitree T) {
	Bitree stack[100], p = T;
	int tag[100];
	int top = 0;
	while (p || top) {
		while (p) {
			top++;
			stack[top] = p;
			p = p->lchild;
			tag[top] = 1;
		}
		if (tag[top] == 1) {
			p = stack[top];
			tag[top] = 2;
			p = p->rchild;
		}
		else {
			p = stack[top];
			printf("%c", p->data);
			top--;
			p = NULL;
		}
	}
}

//�������
void Level(Bitree T) {
	Bitree Q[100], p = T;
	int rear, front;
	rear = front = 0;
	rear++;
	Q[rear] = p;
	while (rear != front) {
		front++;
		p = Q[front];
		printf("%c", p->data);
		if (p->lchild) {
			rear++;
			Q[rear] = p->lchild;
		}
		if (p->rchild) {
			rear++;
			Q[rear] = p->rchild;
		}
	}
}

//�������
void Lever_pro(Bitree T) {
	Bitree Q[100], p = T;
	int rear, front, tag[10], i = 1, j = 0, k = 0, num = 0;
	//i��־������jִ��ѭ����k��־ÿ��Ľ����������kÿ����Ҫ���㣬
	//�ʻ���Ҫ���ñ���num��¼ÿ��Ľ����������ִ��ѭ��
	rear = front = 0;
	rear++;
	Q[rear] = p;
	num = 1;
	while (rear != front) {
		printf("��%d�������Ϊ��", i);
		for (j = 0; j < num; j++) {
			front++;
			p = Q[front];
			printf("%c", p->data);
			if (p->lchild) {
				rear++;
				Q[rear] = p->lchild;
				k++;
			}
			if (p->rchild) {
				rear++;
				Q[rear] = p->rchild;
				k++;
			}
		}
		num = k;
		k = 0;
		printf("\n");
		i++;
	}
}

void Level_pro_pro(Bitree T) {
	Bitree Q[100], p = T;
	int rear, front, nowcount = 0, nextcount = 0, i = 1, tag = 0;
	rear = front = 0;
	rear++;
	Q[rear] = p;
	nowcount = 1;
	while (rear != front) {
		if (tag == 0)
			printf("��%d���Ԫ��Ϊ��", i);
		front++;
		p = Q[front];
		printf("%c", p->data);
		nowcount--;
		if (p->lchild) {
			rear++;
			Q[rear] = p->lchild;
			nextcount++;
		}
		if (p->rchild) {
			rear++;
			Q[rear] = p->rchild;
			nextcount++;
		}
		tag = 1;
		if (nowcount == 0) {
			nowcount = nextcount;
			nextcount = 0;
			i++;
			printf("\n");
			tag = 0;
		}
	}
}


//�������
int Depth(Bitree T) {
	int m, n;
	if (T == NULL)
		return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

//���Ľ����
int NodeCount(Bitree T) {
	if (T)
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	else
		return 0;

}

//ͳ�ƶ������ж�Ϊ0�Ľ��ĸ���
int Node0Count(Bitree T) {
	if (T) {
		if (T->lchild == NULL && T->rchild == NULL)
			return Node0Count(T->lchild) + Node0Count(T->rchild) + 1;
		else
			return Node0Count(T->lchild) + Node0Count(T->rchild);
	}
	else
		return 0;
}

//ͳ�ƶ������ж�Ϊ1�Ľ��ĸ���
int Node1Count(Bitree T) {
	if (T) {
		if (T->lchild != NULL && T->rchild == NULL || T->lchild == NULL && T->rchild != NULL)
			return Node1Count(T->lchild) + Node1Count(T->rchild) + 1;
		else
			return	Node1Count(T->lchild) + Node1Count(T->rchild);
	}
	else
		return 0;

}

//ͳ�ƶ������ж�Ϊ2�Ľ��ĸ���
int Node2Count(Bitree T) {
	if (T) {
		if (T->lchild != NULL && T->rchild != NULL)
			return Node2Count(T->lchild) + Node2Count(T->rchild) + 1;
		else
			return Node2Count(T->lchild) + Node2Count(T->rchild);
	}
	return 0;
}

int main() {
	Bitree T;
	int depth;
	Creat(T);
	printf("ǰ��ǵݹ�Ľ����");
	Fir_Inorder(T);
	printf("\n");
	printf("����ǵݹ�Ľ����");
	Mid_Inorder(T);
	printf("\n");
	printf("����ǵݹ�Ľ����");
	Las_Inorder(T);
	printf("\n");
	printf("����ݹ�Ľ����");
	Level(T);
	printf("\n");
	Lever_pro(T);
	depth = Depth(T);
	printf("�������Ϊ:%d\n", depth);
	printf("���Ľ��ĸ���:");
	printf("%d\n", NodeCount(T));
	printf("��Ϊ0�Ľ��ĸ���:");
	printf("%d\n", Node0Count(T));
	printf("��Ϊ1�Ľ��ĸ���:");
	printf("%d\n", Node1Count(T));
	printf("��Ϊ2�Ľ��ĸ���:");
	printf("%d\n", Node2Count(T));
	return 0;
}