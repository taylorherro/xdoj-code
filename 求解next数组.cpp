#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

int main() {
	int i = 0, j = 0, n;
	char a[MAXSIZE], p[MAXSIZE];
	int next[MAXSIZE];
	scanf("%d\n", &n);
	gets_s(a);
	//去除字符串中的空格 
	for (i = 0; i < 2 * n - 1; i++) {
		if (a[i] != ' ') {
			p[j] = a[i];
			j++;
		}
	}
	//求next表 
	next[0] = -1;
	i = 0;
	j = -1;
	while (i < n) {
		if (j == -1 || p[i] == p[j]) {
			i++; j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	//输出next表
	for (i = 0; i < n; i++) {
		printf("%d ", next[i]);
	}
	return 0;
}