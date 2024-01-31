#include<bits/stdc++.h>
int main()
{
	char str[100];
	int stack[100];
	int top = -1;
	gets_s(str);
	for (int i = 0; str[i] !=0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			top++;
			stack[top] = str[i] - '0';
		}
		else {
			int t1 = stack[top--];
			int t2 = stack[top--];
			if (str[i] == '+')
				stack[++top] = t2 + t1;
			if(str[i] == '-')
			    stack[++top] = t2 - t1;
			if(str[i] == '*')
			    stack[++top] = t2 * t1;
			if (str[i] == '/')
				stack[++top] = t2 / t1;
		}
	}
	printf("%d", stack[top]);
}