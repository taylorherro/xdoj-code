#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
int n;
int count=0;
int juzhen[100][100]={0};
int visited[100]={0};
void dfs(int i)
{
	visited[i]=1;
	printf("%d",i+1);
	for(int j=0;j<n;j++)
	{
		if(juzhen[i][j]==1&&visited[i]==0)
		{
			dfs(j);
		}
	}
}
void dds() 
{
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
		for(int j=0;j<n;j++)
		{
		if(visited[j]==0)
		{
			dfs(j);
			count++;
	}
}
}
int main()
{
	int a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			scanf("%d",&juzhen[i][j]);
		}
	}
	dds();
	
	printf("\n%d",count-1);
}
