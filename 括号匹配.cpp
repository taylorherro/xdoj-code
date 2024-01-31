#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int count = 0;
//栈的定义
typedef struct {
	char data[MAX];
	int top;
}SeqStack;
//栈的初始化
void InitStack(SeqStack* s) {
	s->top = -1;
}
//入栈
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
//取栈顶元素
char GetTop(SeqStack* s)
{
	if (s->top == -1)
	{
		printf("empty");
		return 0;
	}
	return s->data[s->top];
}
//出栈
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
	for (int i = 0; i < strlen(arr); i++)//完成待检测式子的遍历，即输入序列已读尽
	{
		switch (arr[i])
		{
			//遍历式子，遇到左括号放进去，遇到右括号先看是不是一对，如果是则出栈，如果不是count++记录加1
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
	//判断成功的条件是所有左括号都与右括号配对成功而且无被记录的案底
	if (ss.top == -1 && count == 0)
	{
		printf("success");
	}
	else
	{
		printf("fail");
	}
}