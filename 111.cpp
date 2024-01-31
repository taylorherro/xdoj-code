#include<bits/stdc++.h>
using namespace std;
int main()
{
	string ss;
	int n,flag=0;
	cin >> n;
	cin >> ss;
	for (int i = 0; i < n; i++)
	{
		if (ss[i] != ss[n - i - 1])
			flag = 1;
	}
	if (flag == 1)
		printf("NO");
	else
		printf("YES");
}