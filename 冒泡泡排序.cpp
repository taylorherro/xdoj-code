#include<bits/stdc++.h>
int main()
{
	int flag = 0;
	int arr[50];
	int n,n1;
	scanf("%d%d", &n,&n1);
	int n3 = n + n1;
	for (int i = 0; i < n3; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n3-1; i++)
	{
		for (int j = 0; j < n3- 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] = arr[j] ^ arr[j + 1];
				arr[j + 1] = arr[j] ^ arr[j + 1];
				arr[j] = arr[j] ^ arr[j + 1];
				flag++;
			}
		}
	}
	for (int i = 0; i < n3; i++)
		printf("%d ", arr[i]);
}