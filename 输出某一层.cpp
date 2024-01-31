#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct node {
	int data[1000];
	int size;
}bitree;
void create(bitree* t, int arr[], int len)
{
	t->size = len;
	for (int i = 0; i < len; i++)
	{
		t->data[i] = arr[i];
	}
}
void print(bitree* t, int index,int len)
{
	int leftindex = pow(2, index - 1) - 1;
	int size1 = leftindex + pow(2, index - 1);
	if (leftindex > len - 1)
		printf("EMPTY");
	else {
		for (int i = leftindex; i < size1; i++)
		{
			if (i > len-1)
				break;
			else {
				printf("%d ", t->data[i]);
			}
		}
		printf("\n");
	}
}
int main()
{
	int len, arr[1000];
	int index;
	bitree t;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	create(&t, arr, len);
	while (scanf("%d", &index))
	{
		if (index == 0)
			break;
		print(&t, index, len);
	}
}