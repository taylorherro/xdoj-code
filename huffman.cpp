#include <stdio.h>
#define INF 65535

struct huffman {
	int weight;
	int parent, lchild, rchild;
}HT[1001];

void createHT(int n);
int main()
{
	int n;
	scanf("%d", &n);
	int i, sum = 0;
	createHT(n);
	for (i = n; i < 2 * n - 1; i++)		//�����½ڵ�����Ǵ�n->2n-1���ɴ�ȷ���ۼӷ�Χ
		sum += HT[i].weight;
	printf("%d\n", sum);
	return 0;
}

void createHT(int n)
{
	int i, j;
	for (i = 0; i < 2 * n - 1; i++)
		HT[i].parent = HT[i].lchild = HT[i].rchild = -1;	//��ʼ�� 

	for (i = 0; i < n; i++)
		scanf("%d", &HT[i].weight);		//��ʼ�� 

	int a=0, b=0;		//�����ڼ��� 
	int a1, b1;		//������ӦȨ�� 
	for (i = 0; i < n - 1; i++)
	{
		a1 = b1 = INF;
		for (j = 0; j < n + i; j++)
		{
			if (HT[j].parent == -1 && HT[j].weight < a1)	//Ѱ�ұ�a1Ȩ��С����û��˫�׽��Ľ�� 
			{
				b = a;		//����У�����С��˳��ֵ��b 
				a = j;		//a��Ϊ��С����� 
				b1 = a1;	//��СȨ�ظ�ֵb1
				a1 = HT[j].weight;	//��СȨ�ظ�ֵa1 
			}
			else if (HT[j].parent == -1 && HT[j].weight < b1)		//�п�����Ȩ�ش���aС��b,�ٴν����ж� 
			{
				b = j;
				b1 = HT[j].weight;
			}
		}

		HT[n + i].weight = HT[a].weight + HT[b].weight;		//ѡ����С������ 
		HT[n + i].lchild = a;		//˫�׵ĺ��ӽ�� 
		HT[n + i].rchild = b;
		HT[a].parent = HT[b].parent = n + i;  	//˫�׽������ 
	}
}