#include<bits/stdc++.h>
void swap(int *p1,int *p2)
{
	int* X;
    X=p1;
	p1 = p2;
	p2 = X;
}
int main()
{
	int* x1, * x2;
	int a, b;
	scanf("%d%d", &a, &b);
	x1 = &a, x2 = &b;
	swap(x1,x2);
	printf("%d %d",*x1,*x2);
}