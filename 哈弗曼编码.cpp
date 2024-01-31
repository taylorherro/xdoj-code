#include<iostream>
#include<queue>
#include<vector>
//#include<greater>
int num[100];
using namespace std;
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)cin >> num[i];
	int result = 0;
	int num1, num2;
	for (int i = 0; i < n; i++)
		pq.push(num[i]);
	while (pq.size() > 1)
	{
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();
		pq.push(num1 + num2);
		result += num1 + num2;
	}
	cout << result << "\n";
}