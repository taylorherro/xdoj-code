#include<bits/stdc++.h>
void shellsort(int A[], int n) {
	int i, j, k, d = n, temp;
	for (d = n / 2; d > 0; d /= 2)
	{
		for (i = 0; i < d; i++) {//���δ����ӱ� 
			for (j = i + d; j < n; j = j + d) {//����������ӱ� 
				temp = A[j];
				k = j - d;
				while (k >= 0 && A[k] > temp) {
					A[k + d] = A[k];
					k = k - d;
				}
				A[k + d] = temp;
			}
		}
	}
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    shellsort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0; // ��ӣ�����һ������ֵ
}