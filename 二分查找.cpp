#include<bits/stdc++.h>
int half(int arr[], int n,int x,int num[])
{
	int low=0, high=n-1;
	int mid;
	int i = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == x)
		{
			num[i++] = arr[mid];
			return 1;
		}
		else if (arr[mid] < x)
		{
			low = mid+1 ;
			num[i++] = arr[mid];
		}
		else if (arr[mid] > x)
		{
			high = mid-1;
			num[i++] = arr[mid];
		}
	}
	return -1;
}
int main()
{
	int n,x;
	scanf("%d%d", &n, &x);
	int arr[100];
	int num[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	 half(arr, n, x,num);
	 for (int i = 0; num[i] != '\0'; i++)
	 {
		 printf("%d ",num[i]);
	 }
	 if (half(arr, n, x, num)==1)
		 printf("\nEureka!");
	 else
		 printf("\nSearch failed");
}