#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int, vector<int>, greater<int> >pq;
	int n,result=0;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);
	}
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
