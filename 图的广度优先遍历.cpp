#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int num;
	struct Queue* next;
}Queue, * LinkQueue;

typedef struct Pointer
{
	LinkQueue front;
	LinkQueue rear;
}Pointer, * ThePointer;
void EnQueue(int num, ThePointer pointer);
int DeQueue(ThePointer pointer);
int main()
{
	int n;
	int arcs[100][100];
	int i, j;
	int count = 0;
	int visited[100] = { 0 };
	ThePointer pointer = (ThePointer)malloc(sizeof(Pointer));
	pointer->front = (LinkQueue)malloc(sizeof(Queue));
	pointer->rear = pointer->front;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &arcs[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			count++;
			EnQueue(i, pointer);
			visited[i] = 1;
			printf("%d ", i);
			while (pointer->front != pointer->rear)
			{
				int e = DeQueue(pointer);
				for (j = 1; j <= n; j++)
				{
					if (arcs[e][j] == 1 && visited[j] == 0)
					{
						EnQueue(j, pointer);
						visited[j] = 1;
						printf("%d ", j);
					}
				}
			}
		}
	}
	printf("\n%d", count);
	return 0;
}

void EnQueue(int num, ThePointer pointer)
{
	LinkQueue q = (LinkQueue)malloc(sizeof(Queue));
	q->num = num;
	q->next = NULL;
	pointer->rear->next = q;
	pointer->rear = q;
}

int DeQueue(ThePointer pointer)
{
	int e = pointer->front->next->num;
	LinkQueue q = pointer->front->next;
	if (pointer->front->next == pointer->rear)
	{
		pointer->rear = pointer->front;
	}
	pointer->front->next = pointer->front->next->next;
	free(q);
	return e;
}