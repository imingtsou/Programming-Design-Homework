#include<iostream>
#include<cstdio>
using namespace std;
int max(int x,int y)
{
	if (x > y) return x;
	else return y;
}
int main()
{
	int n,a[10010];
	int i,j,k,ans,temp;
	while (scanf("%d",&n) != EOF)
	{
		for (i = 0;i < n;i++) scanf("%d",&a[i]);
		ans = a[0];//确定下界 
		for (i = 0;i < n;i++)
		for (j = i;j < n;j++)
		{
			temp = 0;
			for (k = i;k <= j;k++) temp = temp + a[k];//累加 
			ans = max(ans,temp);
		}
		printf("%d\n\n",ans);
	}
	return 0;
}
