#include<stdio.h>
#include<math.h>
int main()
{
	int n1;
	double sum = 0;
	int min = 0;
	int now;
	scanf("%d", &n1);
	while (n1 != 0)
	{
		min = 0; sum = 0;
		for (int i = 0; i < n1; i++)
		{
			scanf("%d", &now);
			sum += 5.90 * abs((now - min));
			min = now;
		}
		printf("%.2f\n", sum);
		scanf("%d", &n1);
	}
}