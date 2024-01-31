//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//	int n, num[50];
//	cin >> n;
//	int result=0;
//	for (int i = 0; i < n; i++) {
//		cin >> num[i];
//		pq.push(num[i]);
//	}
//	while (pq.size() > 1)
//	{
//		int num1 = pq.top();
//		pq.pop();
//		int num2 = pq.top();
//		pq.pop();
//		pq.push(num1+num2);
//		result += num1 + num2;
//	}
//	cout << result;
//}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, arr[100];
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	int result = 0;
	while (pq.size() > 1)
	{
		int t1 = pq.top();
		pq.pop();
		int t2 = pq.top();
		pq.pop();
		result += t1 + t2;
		pq.push(t1 + t2);
	}
	cout << result << " ";
}