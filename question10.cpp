#include<bits/stdc++.h>
#define maxsize 100001
typedef struct {
	int key;
	int next;
}linklist;
void initlist(linklist* l, int n)
{
	int key, index, next;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &index, &key, &next);
		l[index].key = key;
		l[index].next = next;
	}
}
int removel(linklist* l, int index, int n)
{
	int i, j;
	int abskey = 0;
	while (index != -1)
	{
		abskey = abs(l[index].key);
			i = l[index].next;
			j = index;
			while (i != -1)
			{
				if (abskey == abs(l[i].key))
				{
					l[j].next = l[i].next;
					n--;
				}
				else {
					j = i;
				}
				i = l[i].next;
		}
			index = l[index].next;
	}
	return n;
}
void print(linklist* l, int index, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (l[index].next == -1) {
			printf("%05d %d -1", index, l[index].key);
		}
		else {
			printf("%05d %d %05d\n", index, l[index].key, l[index].next);
		}
		index = l[index].next;
	}
}
int main()
{
	int head, n;
	linklist l[maxsize];
	memset(l, -1, sizeof(linklist));
	scanf("%d%d", &head, &n);
	initlist(l, n);
	int n1 = removel(l, head, n);
	printf("%d\n", n1);
	print(l, head, n1);
}