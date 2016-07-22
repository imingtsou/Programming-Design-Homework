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
	int i,ans,sum;
	while (scanf("%d",&n) != EOF)
	{
		for (i = 0;i < n;i++) scanf("%d",&a[i]);
		ans = a[0];
		for (i = 1;i < n;i++) ans = max(ans,a[i]);//特判下界 
		sum = 0;ans = 0;
		for (i = 0;i < n;i++)
		{
			sum = sum + a[i];
			if (sum > ans) ans = sum;
			else if (sum < 0) sum = 0;//若小于0则舍去 
		}
		printf("%d\n\n",ans);
	}
	return 0;
}
