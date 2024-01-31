#include<bits/stdc++.h>
using namespace std;
int QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return 1;
	int left = begin;
	int right = end;
	int temp;
	temp = arr[begin];
	while (begin < end)
	{
		//右边选小   等号防止和key值相等    防止顺序begin和end越界
		while (arr[end] >= temp && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//左边选大
		while (arr[begin] <= temp && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
		//小的换到右边，大的换到左边
	}
	arr[begin] = temp;
	return begin;
}
void qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int temp = QuickSort(arr, low, high);
		qsort(arr, low, temp - 1);
		qsort(arr, temp + 1, high);
	}
}
int main()
{
	int n;
	cin >> n;
	int arr[500];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}