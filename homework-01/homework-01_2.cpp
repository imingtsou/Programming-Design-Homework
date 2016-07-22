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
	int i,j,ans,sum;
	while (scanf("%d",&n) != EOF)
	{
		for (i = 0;i < n;i++) scanf("%d",&a[i]);
		ans = a[0];//确定下界 
		for (i = 0;i < n;i++)
		{
			sum = 0;
			for (j = i;j < n;j++)
			{
				sum = sum + a[j];//从上一步继续加 
				ans = max(ans,sum);
			}
		}
		printf("%d\n\n",ans);
	}
	return 0;
}
