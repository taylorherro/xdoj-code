#include<stdio.h>
int main()
{
	int m,n;
	int arr[1000];
	scanf("%d%d",&m,&n);
	for(int i=0;i<m*n;i++)
	scanf("%d",&arr[i]);
	int flag[1000]={0};
	int fla=0;
	for(int i=0;i<m*n;i+=n)
	{
		for(int j=n;j<m*n;j+=n)
		{
			for(int k=0;k<n;k++)
			{
				if(arr[i+k]>=arr[j+k])
				{
				fla=1;
				break;
			    }
			}
			if(fla==0)
			{
			flag[i]=i/n;
			break;
		}
			fla=0;
		}
	}
	fla=1;
	for(int s=0;s<m;s+=n)
	{
		if(flag[s]==0)
		{
			for(int i=0;i<m*n;i+=n)
			{
				for(int j=n;j<m*n;j+=n)
				{
					for(int k=0;k<n;k++)
					{
					if(arr[i+k]<=arr[j+k])
					{
						fla=1;
						break;
					}
				}
				if(fla==0)
			{
			flag[s]=i/n;
			break;
		}
			fla=0;
		}
			}
		}
	}
	for(int i=0;i<m*n;i+=n)
	{
		if(flag[i]!=0)
		printf("%d\n",flag[i]);
		else
		printf("%d\n",flag[i]);
	}
	return 0;
}
