#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int count = 0;
//ջ�Ķ���
typedef struct {
	char data[MAX];
	int top;
}SeqStack;
//ջ�ĳ�ʼ��
void InitStack(SeqStack* s) {
	s->top = -1;
}
//��ջ
void PushStack(char c, SeqStack* s)
{
	if (s->top == MAX - 1)
	{
		printf("full");
		return;
	}
	s->top++;
	s->data[s->top] = c;
}
//ȡջ��Ԫ��
char GetTop(SeqStack* s)
{
	if (s->top == -1)
	{
		printf("empty");
		return 0;
	}
	return s->data[s->top];
}
//��ջ
void PopStack(SeqStack* s)
{
	if (s->top == -1)
	{
		printf("empyt");
	}
	s->top--;
}
int main()
{
	SeqStack ss;
	InitStack(&ss);
	char temp;
	char arr[100];
	gets_s(arr);
	for (int i = 0; i < strlen(arr); i++)//��ɴ����ʽ�ӵı����������������Ѷ���
	{
		switch (arr[i])
		{
			//����ʽ�ӣ����������ŷŽ�ȥ�������������ȿ��ǲ���һ�ԣ���������ջ���������count++��¼��1
		case '[':
			PushStack(arr[i], &ss);
			break;
		case '{':
			PushStack(arr[i], &ss);
			break;
		case '(':
			PushStack(arr[i], &ss);
			break;
		case ']':
			temp = GetTop(&ss);
			if (temp == '[')
			{
				PopStack(&ss);
			}
			else
			{
				count++;
			}
			break;
		case '}':
			temp = GetTop(&ss);
			if (temp == '{')
			{
				PopStack(&ss);
			}
			else
			{
				count++;
			}
			break;
		case ')':
			temp = GetTop(&ss);
			if (temp == '(')
			{
				PopStack(&ss);
			}
			else
			{
				count++;
			}
			break;
		default:
			continue;
			break;
		}
	}
	//�жϳɹ������������������Ŷ�����������Գɹ������ޱ���¼�İ���
	if (ss.top == -1 && count == 0)
	{
		printf("success");
	}
	else
	{
		printf("fail");
	}
}