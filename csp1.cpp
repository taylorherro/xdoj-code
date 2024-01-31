#include<stdio.h>
int main()
{
	int n,m;
	int xi=0,yi=0;
	int x=0,y=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&xi,&yi);
		x+=xi;
		y+=yi;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&xi,&yi);
		xi=xi+x;yi=yi+y;
		printf("%d %d\n",xi,yi);
	}
	return 0;
}
