#include <queue>
#include <iostream>
#include <algorithm>
//#include<algorithm>
#include<algorithm>
using namespace std;

int main() {
	queue<int> q;
	queue<int> r;
	int n, k0, num = 1;
	cin >> n >> k0;
	int k1[50] = { 0 };
	for (int i = 0; i < n; i++)
		cin>>k1[i];
	for (int i = 0; i < n; i++)
		r.push(k1[i]);
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		if (num == k0) {
			cout << q.front() << " ";
			q.pop();
			k0 = r.front();
			r.pop();
			num = 1;
			// 将k1数组向前移动一位
		}
		else {
			q.push(q.front());
			q.pop();
			num++;
			r.push(r.front());
			r.pop();
		}
	}

	return 0;
}