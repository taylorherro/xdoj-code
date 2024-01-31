#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ���ֲ��ң��ҵ�Ԫ�ط�������ֵ�����򷵻�-1
int binarySearch(int arr[], int len, int target) {
	int low = 0, high = len - 1, mid; // ��Сֵ�����ֵ���м�ֵ���±�
	while (low <= high) {
		mid = (low + high) / 2; // ÿ��ѭ�����¸�mid��ֵ���ı��м�ֵ���±�
		if (arr[mid] == target) { // ����м�ֵ����Ŀ��ֵ��˵�����ҳɹ��������±�
			return mid;
		}
		else if (arr[mid] > target) { // ����м�ֵ����Ŀ��ֵ��˵��Ŀ��ֵ�����ߣ���ʱ�����Ұ��
			high = mid - 1;
		}
		else { // ����м�ֵС��Ŀ��ֵ��˵��Ŀ��ֵ���Ұ�ߣ���ʱ��������
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

