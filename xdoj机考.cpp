#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

int juzhen[MAXSIZE][MAXSIZE] = { 0 };
int visited[MAXSIZE] = { 0 };
int visited2[MAXSIZE] = { 0 };//说明当前顶点在栈中

int count = 0;//有环不为0
int num[MAXSIZE] = { 0 }; //存储是否有环
int times = 0;

void DFS(int i, int m) {
	int j;
	visited[i] = 1;
	visited2[i] = 1;
	for (j = 0; j < m; j++) {
		if (visited[j] == 0 && juzhen[i][j] != 0) {
			DFS(j, m);
		}
		else if (visited[j] == 1 && juzhen[i][j] != 0 && visited2[j] == 1 && i != j) {
			count++;
		}
	}
}
void visited2T0() {
	int i;
	for (i = 0; i < MAXSIZE; i++) {
		visited2[i] = 0;
	}

}
void DDFS(int m) {
	int i = 0;
	for (i = 0; i < MAXSIZE; i++) {
		visited[i] = 0; //初始化
	}
	for (i = 0; i < m; i++) {
		visited2T0();
		if (visited[i] == 0) {
			DFS(i, m);
		}
		if (count != 0) {
			break;
		}

	}

}

void IfEXist() {
	int i, j, m;
	count = 0;  //清零
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &juzhen[i][j]);
		}
	}
	DDFS(m);
	if (count == 0) {
		num[times] = 0;
	}
	else {
		num[times] = 1;
	}
	times++;

}

void ToZero() {

	int i, j;
	for (i = 0; i < MAXSIZE; i++) {
		for (j = 0; j < MAXSIZE; j++) {
			juzhen[i][j] = 0;
		}
	}
}

int main() {
	int a, b;
	int i, j, k;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		ToZero();
		IfEXist();

	}
	for (i = 0; i < n; i++) {
		printf("%d", num[i]);
	}
	return 0;
}