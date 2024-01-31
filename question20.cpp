#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sequeue
{
	int data[1000];
	int front = -1, rear = -1;
}seq;
seq* sq, * s;
int frq(seq* sq)
{
	int ret;
	ret = sq->data[(sq->front + 1) % 1000];
	return ret;
}
void enq(seq* sq, int x)
{
	sq->rear = (sq->rear + 1) % 1000;
	sq->data[sq->rear] = x;
}
int deq(seq* sq)
{
	int ret;
	sq->front = (sq->front + 1) % 1000;
	ret = sq->data[sq->front];
	return ret;
}
int main()
{
	int n, i, x, t, f, j;
	scanf("%d", &n);
	sq = (seq*)malloc(sizeof(seq));
	s = (seq*)malloc(sizeof(seq));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		enq(sq, x);
	}
	j = n;
	while (j != 0)
	{
		t = frq(sq);
		for (i = 0; i < j; i++)
		{
			f = deq(sq);
			if (t > f) t = f;
			enq(s, f);
		}
		for (i = 0; i < j; i++)
		{
			f = deq(s);
			if (f != t) enq(sq, f);
		}
		j--;
		printf("%d", t);
		if (j != 0) printf(" ");
	}
	return 0;
}
