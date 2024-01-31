#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, i, j, top, num;
	int a[100], b[100], stack[100];
	int flag = 1;
	top = 0;//栈顶，入栈时栈顶加一再赋值，出栈时栈顶减一，top等于0时表示栈空
	stack[top] = -10;//使第一次时栈顶元素小于出栈序列，从而入栈
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		a[i] = i;//入栈序列 123456
		scanf("%d", &b[i]);//出栈序列 342156
	}
	num = n;
	i = 1; j = 1;//从入栈序列和出栈序列的第一个元素开始
	while (num != 0)//出栈序列没有检测完
	{
		if (b[i] < stack[top])//如果栈顶元素大于出栈序列元素：则说明出错，flag=0，退出循环。
		{
			flag = 0;
			break;
		}
		if (b[i] > stack[top])//栈顶元素小于出栈序列元素
		{
			while (b[i] > stack[top])//入栈，直到栈顶元素等于出栈序列
			{
				top++;
				stack[top] = a[j++];
			}
		}
		if (b[i] == stack[top])//栈顶元素等于出栈序列
		{
			top--;//出栈
			i++;//出栈序列开始检验下一个
			num--;//出栈序列还有num个（其实设置的num有点多余）
		}
		if (num == 0 && top == 0 && i == n + 1 && j == n + 1)// 如果最后栈空，且出栈序列已经被全部检测完，且入栈序列全部入过栈则说明成功
			flag = 1;
		else
			flag = 0;
	}
	if (flag)
		printf("yes");
	else
		printf("no");
	return 0;
}
