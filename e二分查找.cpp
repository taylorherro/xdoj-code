#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 二分查找，找到元素返回索引值，否则返回-1
int binarySearch(int arr[], int len, int target) {
	int low = 0, high = len - 1, mid; // 最小值、最大值和中间值的下标
	while (low <= high) {
		mid = (low + high) / 2; // 每次循环重新给mid赋值，改变中间值的下标
		if (arr[mid] == target) { // 如果中间值等于目标值，说明查找成功，返回下标
			return mid;
		}
		else if (arr[mid] > target) { // 如果中间值大于目标值，说明目标值在左半边，此时缩减右半边
			high = mid - 1;
		}
		else { // 如果中间值小于目标值，说明目标值在右半边，此时缩减左半边
			low = mid + 1;
		}
	}
	return -1;
}

int main() {
	int a[50];
	int n,target;
	scanf("%d", &n); scanf("%d", &target);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int index;
	index = binarySearch(a, n, target);
	printf("%d",index);
	return 0;
}

