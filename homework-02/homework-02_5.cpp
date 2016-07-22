#include<iostream>
#include<cstdio>
#include<time.h>
#include<cstring>
using namespace std;
int a[1010][1010];
int b[1010][1010];
int max(int x,int y)
{
	if (x > y) return x;
	else return y;
}
int main()
{
	freopen("input.txt","r",stdin);
	clock_t start,finish;
	start = clock();
	double totaltime;
	int m,n;
	int i,j,k,ans,temp = 0;
	scanf("%d,",&m);
	scanf("%d,",&n);
	for (i = 1;i <= m;i++)
	for (j = 1;j <= n;j++)
	{
		scanf("%d,",&a[i][j]);
		a[i + m][j] = a[i][j];
	}
	ans = a[1][1];
	for (i = 1;i <= m;i++)
	for (j = 1;j <= n;j++) ans = max(ans,a[i][j]);
	memset(b,0,sizeof(b));
	for (j = 1;j <= n;j++)
	{
		temp = 0;
		for (i = 1;i <= m * 2;i++)
		{
			temp = temp + a[i][j];
			b[i][j] = temp;
		}
	}
	for (i = 1;i <= m;i++)
	for (j = i;j <= m;j++)
	{
		if ((j - i) <= m)
		{
			temp = 0;
			for (k = 1;k <= n;k++)
			{
				temp = temp + b[j][k] - b[i - 1][k];
				if (temp > ans) ans = temp;
				else if (temp < 0) temp = 0;
			}
		}
	}
	printf("%d\n",ans);
	finish = clock();
	totaltime = finish - start;
	printf("%lf\n",totaltime);
	fclose(stdin);
	return 0;
}
