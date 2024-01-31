#include <stdio.h>
void merge_sort(int* a, int L, int mid, int R);
void process(int* a, int L, int R);


void process(int* a, int L, int R) {
    if (L == R)
        return;
    int mid = L + ((R - L) / 2);//计算中点
    process(a, L, mid);
    process(a, mid + 1, R);
    merge_sort(a, L, mid, R);
}

void merge_sort(int* a, int L, int mid, int R) {
    int arr[100];

    int i = L;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= R) {
        arr[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }

    while (i <= mid) {
        arr[k++] = a[i++];
    }

    while (j <= R) {
        arr[k++] = a[j++];
    }

    for (k = L; k <= R; k++) {
        a[k] = arr[k - L];
    }
}

int main() {
    int n;
    printf("数组长度：");
    scanf("%d", &n);
    int a[100];
    printf("请输入一组数：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    process(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


