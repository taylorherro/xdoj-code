#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[50];
	scanf("%s", &str);
	int length = strlen(str);
	int flag=1,i=1;
	for ( i = 1; i <=length; i++)
	{
		if (length % i == 0)
		{
			flag = 1;
			for (int j = i; j <length; j++)
			{
				if (str[j] != str[j % i])
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
		{
			printf("%d\n", i);
			break;
		}
	}
}