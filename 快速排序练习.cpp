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
		//�ұ�ѡС   �Ⱥŷ�ֹ��keyֵ���    ��ֹ˳��begin��endԽ��
		while (arr[end] >= temp && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//���ѡ��
		while (arr[begin] <= temp && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
		//С�Ļ����ұߣ���Ļ������
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