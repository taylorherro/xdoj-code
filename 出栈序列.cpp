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
		if (arr[i + 1] > arr[i])//升序认定合理
		{
			i++;
			continue;
		}
		else
		{
			t = arr[i];//记录升序结束部分的数字
			i++;
			while (i < n - 1)
			{
				if (arr[i] > arr[i + 1])//降序认定合理
				{
					i++;
					continue;
				}
				else if (arr[i + 1] > t)//降序结束的数字大于升序结束部分的数字，认定合理
				{
					break;
				}
				else//降序结束的数字小于升序结束部分的数字，不合理
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