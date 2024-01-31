#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int* base;//储存空间的基地址
	int front;//头指针
	int rear;//尾指针
	int maxsize;//队列最大长度
}SqQueue;
//初始化
SqQueue* InitQueue(int size) {
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));//先创建队列结构体指针
	Q->base = (int*)malloc(sizeof(int) * size);//为队列分配一个最大容量为size的数组空间
	//队列最大长度置为size，头指针尾指针置为0，队列为空
	Q->maxsize = size;
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
//输出
void print(SqQueue* Q) {
	printf("(front) ");
	int i;
	//跟遍历数组差不多，就是要通过模运算防止越界
	for (i = Q->front; i != Q->rear; i = (i + 1) % Q->maxsize) {
		printf("%d ", Q->base[i]);
	}
	printf("(rear)\n");
}
//入队
bool EnQueue(SqQueue* Q, int e) {
	//插入e作为新队尾元素
	if ((Q->rear + 1) % Q->maxsize == Q->front)	return false;//尾指针在循环意义上加1后等于头指针说明队满
	Q->base[Q->rear] = e;//将元素e插入队尾
	Q->rear = (Q->rear + 1) % Q->maxsize;//尾指针加1
	return true;
}
//出队
bool DeQueue(SqQueue* Q, int* e) {
	//删除队头元素，用e返回其值
	if (Q->front == Q->rear)	return false;//队空
	*e = Q->base[Q->front];//用e保存队头元素
	Q->front = (Q->front + 1) % Q->maxsize;//头指针加1
	return true;
}
//取队头元素
bool GetHead(SqQueue* Q, int* e) {
	//返回队头元素，不修改头指针
	if (Q->front == Q->rear)	return false;//队空
	*e = Q->base[Q->front];
	return true;
}
//求队列长度
int QueueLength(SqQueue* Q) {
	//返回队列元素个数
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