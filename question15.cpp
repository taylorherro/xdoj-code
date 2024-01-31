#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int flag1[1000][1000];
int flag2[1000][1000];
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		int minval = 1e6, minindex = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < minval)
			{ 
				minval = a[i][j];
				minindex = j;
		}
	}
		bool flag1[i][minindex] = 1;
		for (int j = 0; j < m; j++)
		{

		}
}
}
