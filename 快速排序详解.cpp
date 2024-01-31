#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void QuickSort_dig(int arr[], int begin, int end)
{
	if (begin >= end)
		return;
	int key = arr[begin];
	int piti = begin;
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[piti] = arr[right];
		piti = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[piti] = arr[left];
		piti = left;
	}
	//²¹¿Ó
	arr[piti] = key;
	//[begin, piti - 1] piti [piti + 1, end]
	QuickSort_dig(arr, begin, piti - 1);
	QuickSort_dig(arr, piti + 1, end);
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
	int n1,n2;
	scanf("%d", &n1);
	int arr[1000];
	for (int i = 0; i < n1; i++)
		scanf("%d", &arr[i]);
	QuickSort_dig(arr, 0, n1 - 1);
	print(arr,n1);
}