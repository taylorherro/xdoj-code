//#include<bits/stdc++.h>
//void mergesort(int arr[],int l,int mid,int r);
//void process(int arr[], int l, int r)
//{
//	if (l == r)
//		return;
//	int mid = l + ((r-l) / 2);
//	process(arr, l, mid);
//	process(arr, mid + 1, r);
//	mergesort(arr, l, mid, r);
//}
//void mergesort(int arr[], int l, int mid, int r)
//{
//	int a[100] = {0};
//	int i = l;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid && j <= r)
//	{
//		a[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
//	}
//	while (i <= mid)
//		a[k++] = arr[i++];
//	while (j <= r)
//		a[k++] = arr[j++];
//	for (int k = l; k <=r; k++)
//		arr[k] = a[k - l];
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100];
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	process(arr, 0, n - 1);
//	for (int i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
#include<bits/stdc++.h>
void mergesort(int arr[], int l, int mid, int r)
{
	int a[100] = { 0 };
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r)
	{
		a[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}
	while (i <= mid)
		a[k++] = arr[i++];
	while (j <= r)
		a[k++] = arr[j++];
	for (int k = l; k <= r; k++)
		arr[k] = a[k - l];
}
void process(int arr[], int l, int r)
{
	if (l == r)
		return;
	int mid = l + ((r - l) / 2);
	process(arr, l, mid);
	process(arr, mid + 1, r);
	mergesort(arr, l, mid, r);
}
int main()
{
	int n;
	int arr[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	process(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}