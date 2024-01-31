////#include<bits/stdc++.h>
////int n,num;
////int arr[101], brr[101];
////int early[101], later[101];
////int min(int a, int b)
////{
////	return a < b ? a : b;
////}
////int main()
////{
////	scanf("%d%d", &n, &num);
////	for (int i = 1; i <= num; i++)
////	{
////		scanf("%d", &arr[i]);
////	}
////	for (int i = 1; i <=num; i++)
////	{
////		scanf("%d", &brr[i]);
////	}
////	int mark = 1;
////	for (int i = 1; i <=num; i++)
////	{
////		if (arr[i] == 0)
////			early[i] = 1;
////		else
////		{
////			early[i] =early[arr[i]] + brr[arr[i]];
////		}
////		if (early[i] + brr[i] - 1 > n)
////			mark = 0;
////	}
////	for (int i = 1; i <=num; i++)
////		printf("%d ", early[i]);
////	printf("\n");
////	int cdd,now;
////	if (mark == 1)
////	{
////		for (int i = num; i >= 1; i--)
////		{
////			int temp = 366;
////			for (int j = i + 1; j <= num; j++)
////			{
////				if (arr[j] == i)
////					temp = min(temp, later[j]);
////			}
////			if (temp == 366)
////				later[i] = n - brr[i] + 1;
////			else
////				later[i] = temp - brr[i];
////		}
////
////		for (int i = 1; i <= num; i++)
////			printf("%d ", later[i]);
////		printf("\n");
////	}
////	return 0;
////}
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//const int N = 10005;
//int main()
//{
//	int arr[N];
//	int x;
//	int n;
//	cin >> n;
//	for (int i = 1; i <=n; i++)
//	{
//		cin >>x;
//		arr[x]++;
//	}
//	int rs = 0;
//	for (int i = 1; i < N; i++)
//		if (arr[i]>arr[rs])
//			rs = i;
//	cout <<rs<< endl;
//}
#include<iostream>
using namespace std;
int main()
{
	string arr;
	cin >> arr;
	cout << sizeof(arr);
}