#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int* base;//����ռ�Ļ���ַ
	int front;//ͷָ��
	int rear;//βָ��
	int maxsize;//������󳤶�
}SqQueue;
//��ʼ��
SqQueue* InitQueue(int size) {
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));//�ȴ������нṹ��ָ��
	Q->base = (int*)malloc(sizeof(int) * size);//Ϊ���з���һ���������Ϊsize������ռ�
	//������󳤶���Ϊsize��ͷָ��βָ����Ϊ0������Ϊ��
	Q->maxsize = size;
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
//���
void print(SqQueue* Q) {
	printf("(front) ");
	int i;
	//�����������࣬����Ҫͨ��ģ�����ֹԽ��
	for (i = Q->front; i != Q->rear; i = (i + 1) % Q->maxsize) {
		printf("%d ", Q->base[i]);
	}
	printf("(rear)\n");
}
//���
bool EnQueue(SqQueue* Q, int e) {
	//����e��Ϊ�¶�βԪ��
	if ((Q->rear + 1) % Q->maxsize == Q->front)	return false;//βָ����ѭ�������ϼ�1�����ͷָ��˵������
	Q->base[Q->rear] = e;//��Ԫ��e�����β
	Q->rear = (Q->rear + 1) % Q->maxsize;//βָ���1
	return true;
}
//����
bool DeQueue(SqQueue* Q, int* e) {
	//ɾ����ͷԪ�أ���e������ֵ
	if (Q->front == Q->rear)	return false;//�ӿ�
	*e = Q->base[Q->front];//��e�����ͷԪ��
	Q->front = (Q->front + 1) % Q->maxsize;//ͷָ���1
	return true;
}
//ȡ��ͷԪ��
bool GetHead(SqQueue* Q, int* e) {
	//���ض�ͷԪ�أ����޸�ͷָ��
	if (Q->front == Q->rear)	return false;//�ӿ�
	*e = Q->base[Q->front];
	return true;
}
//����г���
int QueueLength(SqQueue* Q) {
	//���ض���Ԫ�ظ���
	return (Q->rear - Q->front + Q->maxsize) % Q->maxsize;
}
int main() {
	int i, n, e;
	SqQueue* Q = InitQueue(5);
	for (scanf("%d", &n), i = 0; i < n; i++) {
		scanf("%d", &e);
		EnQueue(Q, e);
	}
	print(Q);
	DeQueue(Q, &e);
	printf("e=%d\n", e);
	DeQueue(Q, &e);
	printf("e=%d\n", e);
	DeQueue(Q, &e);
	printf("e=%d\n", e);
	for (scanf("%d", &n), i = 0; i < n; i++) {
		scanf("%d", &e);
		EnQueue(Q, e);
	}
	print(Q);
}