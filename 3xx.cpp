#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
void postOrder(string first, string middle);
int index = 0;
int main() {
	string first, middle, result;
	cin >> first >> middle;
	postOrder(first, middle);
	return 0;
}
void postOrder(string first, string middle) {
	if (middle.length() == 0)
		return;
	char ch = first[index++];
	int pos = middle.find(ch);
	string left = middle.substr(0, pos);
	string right = middle.substr(pos + 1);
	postOrder(first, left);
	postOrder(first, right);
	cout << ch;
}

