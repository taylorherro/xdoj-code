#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, i, j, top, num;
	int a[100], b[100], stack[100];
	int flag = 1;
	top = 0;//ջ������ջʱջ����һ�ٸ�ֵ����ջʱջ����һ��top����0ʱ��ʾջ��
	stack[top] = -10;//ʹ��һ��ʱջ��Ԫ��С�ڳ�ջ���У��Ӷ���ջ
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		a[i] = i;//��ջ���� 123456
		scanf("%d", &b[i]);//��ջ���� 342156
	}
	num = n;
	i = 1; j = 1;//����ջ���кͳ�ջ���еĵ�һ��Ԫ�ؿ�ʼ
	while (num != 0)//��ջ����û�м����
	{
		if (b[i] < stack[top])//���ջ��Ԫ�ش��ڳ�ջ����Ԫ�أ���˵������flag=0���˳�ѭ����
		{
			flag = 0;
			break;
		}
		if (b[i] > stack[top])//ջ��Ԫ��С�ڳ�ջ����Ԫ��
		{
			while (b[i] > stack[top])//��ջ��ֱ��ջ��Ԫ�ص��ڳ�ջ����
			{
				top++;
				stack[top] = a[j++];
			}
		}
		if (b[i] == stack[top])//ջ��Ԫ�ص��ڳ�ջ����
		{
			top--;//��ջ
			i++;//��ջ���п�ʼ������һ��
			num--;//��ջ���л���num������ʵ���õ�num�е���ࣩ
		}
		if (num == 0 && top == 0 && i == n + 1 && j == n + 1)// ������ջ�գ��ҳ�ջ�����Ѿ���ȫ������꣬����ջ����ȫ�����ջ��˵���ɹ�
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
