#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
void headadjust(int arr[],int k,int len)
{
	arr[0]=arr[k];
	for(int i=2*k;i<=len;i*=2)
	{
		if(i<len&&arr[i]<arr[i])
		i++;
		if(arr[0]>arr[i]) break;
		else{
		     arr[k]=arr[i];
		     k=i;
		}
	}
	arr[k]=arr[0];
}
void headheap(int arr[],int len)
{
	for(int i=len/2;i>0;i--)
	{
		headadjust(arr,i,len);
	}
}
void headsort(int arr[],int len)
{
	headheap(arr,len);
	for(int i=len;i>1;i--)
	{
		arr[i]=arr[i]^arr[1];
		arr[1]=arr[i]^arr[1];
		arr[i]=arr[i]^arr[1];
		headadjust(arr,1,i-1);
	}
}
int main()
{
	int len;
	int arr[100];
	scanf("%d",&len);
	for(int i=1;i<=len;i++)
	scanf("%d",&arr[i]);
	headsort(arr,len);
	for(int i=1;i<=len;i++)
	printf("%d ",arr[i]);
}

