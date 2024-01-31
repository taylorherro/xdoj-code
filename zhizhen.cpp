#include <stdio.h>
#include <math.h>
#include <malloc.h>

void quicksort(int arr[], int begin, int end) {
	if (begin > end)
		return;
	int left = begin;
	int right = end;
	int piti = begin;
	int temp = arr[begin];
	while (left < right) {
		while (left < right && arr[right] >= temp) {
			right--;
		}
		arr[piti] = arr[right];
		piti = right;
		while (left < right && arr[left] <= temp) {
			left++;
		}
		arr[piti] = arr[left];
		piti = left;
	}
	arr[piti] = temp;
	quicksort(arr, begin, piti - 1);
	quicksort(arr, piti + 1, end);
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int arr[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	quicksort(arr, 0, n - 1);
	print(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}