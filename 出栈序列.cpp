#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	int arr[15];
	int i;
	int t;
	int flag = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n - 1; )
	{
		if (arr[i + 1] > arr[i])//�����϶�����
		{
			i++;
			continue;
		}
		else
		{
			t = arr[i];//��¼����������ֵ�����
			i++;
			while (i < n - 1)
			{
				if (arr[i] > arr[i + 1])//�����϶�����
				{
					i++;
					continue;
				}
				else if (arr[i + 1] > t)//������������ִ�������������ֵ����֣��϶�����
				{
					break;
				}
				else//�������������С������������ֵ����֣�������
				{
					flag = 0;
					break;
				}
			}
		}
	}
	if (flag == 1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}