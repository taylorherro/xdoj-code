#include<bits/stdc++.h>
void insertsort(int arr[], int n)
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)
	{
		if (arr[i] < arr[i-1])
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int arr[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	insertsort(arr, n);
	print(arr, n);
}
//void insertsort(int arr[], int n)
//{
//	int i, j, tmep;
//	for (i = 1; i < n; i++)
//	{
//		if (arr[i] < arr[i - 1])
//		{
//			tmep = arr[i];
//			for (j = i - 1; j >= 0 && arr[j] > tmep; j--)
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[j + 1] = tmep;
//		}
//	}
//}