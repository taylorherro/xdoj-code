#include<bits/stdc++.h>
int count=0;
int tree(int m, int n)
{
	if (2 * m <= n)
	{
		count++;
		tree(2 * m, n);
	}
	if (2 * m + 1 <= n)
	{
		count++;
		tree(2 * m + 1, n);
	}
	return count;
}
int main()
{
	int m, n,i=0;
	int val[100];
	while (scanf("%d %d", &m, &n) == 2 && m != 0 && n != 0)
	{
		val[i++] = tree(m, n)+1;
		count = 0;
	}
	for (int j = 0; j < i; j++)
	{
		printf("%d\n",val[j]);
	}
	return 0;
}

