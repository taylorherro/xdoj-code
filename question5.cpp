#include<stdio.h>
#include<stdlib.h>

//������ṹ�� 
typedef struct queue {
	int num;
	struct queue* next;
}QNode, * Queue;

//��ͷ�巨������������1��N 
void Create(Queue* q, int N) {
	Queue node;
	int i;
	*q = (Queue)malloc(sizeof(QNode));
	(*q)->next = NULL;
	for (i = N; i > 0; i--) {
		node = (Queue)malloc(sizeof(QNode));
		node->num = i;
		node->next = (*q)->next;
		(*q)->next = node;
	}
}

//���������� 
void Out(Queue* q, int N) {
	int i;
	int count = N;	//��¼���и��� 
	Queue p, t;
	//������������3ʱ����ѭ��
	while (N > 3) {
		//����2�ı������˳��� 
		p = (*q)->next;
		t = (*q);
		N = count;
		for (i = 1; i <= N; i++) {
			if (i % 2 == 0) {
				t->next = p->next;
				p = p->next;
				count--;
			}
			else {
				p = p->next;
				t = t->next;
			}
		}
		if (count <= 3)	//ע����һ�ֽ������жϣ������ڳ���ʱ����ж� 
			return;
		//����3�ı������˳��� 
		p = (*q)->next;
		t = (*q);
		N = count;
		for (i = 1; i <= N; i++) {
			if (i % 3 == 0) {
				t->next = p->next;
				p = p->next;
				count--;
			}
			else {
				p = p->next;
				t = t->next;
			}
		}
		if (count <= 3)
			return;
	}

}

//������� 
void Print(Queue head) {
	Queue p;
	p = head->next;
	while (p != NULL) {
		printf("%d ", p->num);
		p = p->next;
	}
}

int main() {
	Queue q;
	int N;
	scanf("%d", &N);
	Create(&q, N);
	Out(&q, N);
	Print(q);
	return 0;
}