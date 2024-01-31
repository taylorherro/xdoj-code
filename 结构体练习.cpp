#include<bits/stdc++.h>
struct purchased {
	int id;
	char name[100];
	int quantity;
};
void bubblesort(struct purchased arr[], int n)
{
	int i, j;
	struct purchased temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].quantity > arr[j + 1].quantity)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d", arr[i].id, arr[i].name, arr[i].quantity);
		printf("\n");
	}
}
int main()
{
	int n;
	struct purchased arr[100];
	scanf("%d", &n);  
	for (int i = 0; i < n; i++)
		scanf("%d%s%d", &arr[i].id,arr[i].name, &arr[i].quantity);
	bubblesort(arr, n);
	return 0;
}