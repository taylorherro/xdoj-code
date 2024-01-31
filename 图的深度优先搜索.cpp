//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAXSIZE 1000
//int juzhen[MAXSIZE][MAXSIZE] = { 0 };
//int visited[MAXSIZE] = { 0 };
//int m;
//int count = 0;
//void DFS(int i) {
//	int j;
//	visited[i] = 1;
//	printf("%d ", i + 1);
//	for (j = 0; j < m; j++) {
//		if (visited[j] == 0 && juzhen[i][j] != 0) {
//			DFS(j);
//		}
//	}
//}
//
//void DDFS() {
//	int i = 0;
//	for (i = 0; i < m; i++) {
//		visited[i] = 0; //³õÊ¼»¯
//	}
//	for (i = 0; i < m; i++) {
//		if (visited[i] == 0) {
//			DFS(i);
//			count++;
//		}
//	}
//
//}
//int main() {
//	int a, b;
//	int i, j, k;
//
//	scanf("%d", &m);
//
//	for (i = 0; i < m; i++) {
//		for (j = 0; j < m; j++) {
//			scanf("%d", &juzhen[i][j]);
//		}
//	}
//
//	DDFS();
//	printf("\n");
//	printf("%d", count);
//	return 0;
//}
#include<bits/stdc++.h>
int m;
int count = 0;
int visited[100];
int juzhen[100][100];
void dfs(int i)
{
	int j;
	visited[i] = 1;
	printf("%d ", i + 1);
	for (j = 0; j < m; j++)
	{
		if (visited[j] == 0 && juzhen[i][j] != 0)
		{
			dfs(j);
		}
	}
}
void dds()
{
	for (int i = 0; i < m; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			count++;
		}
	}
}
int main()
{
	scanf("%d", &m);
	int n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &juzhen[i][j]);
		}
	}
	dds();
	printf("\n%d", count);
}