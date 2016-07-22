#include<iostream>
#include<cstdio>
#include<time.h>
#include<cstring>
using namespace std;
int a[1010][1010];
int b[101][101][101];
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
	for (i = 0;i < m;i++)
	for (j = 0;j < n;j++) scanf("%d,",&a[i][j]);
	ans = a[0][0];
	for (i = 0;i < m;i++)
	for (j = 0;j < n;j++) ans = max(ans,a[i][j]);
	memset(b,0,sizeof(b));
	for (k = 0;k < n;k++)
	{
		for (i = 0;i < m;i++)
		{
			temp = 0;
			for (j = i;j < m;j++)
			{
				temp = temp + a[j][k];
				b[i][j][k] = temp;
			}
		}
	}
	for (i = 0;i < m;i++)
	for (j = i;j < m;j++)
	{
		temp = 0;
		for (k = 0;k < n;k++)
		{
			temp = temp + b[i][j][k];
			if (temp > ans) ans = temp;
			else if (temp < 0) temp = 0;
		}
	}
	printf("%d\n",ans);
	finish = clock();
	totaltime = finish - start;
	printf("%lf\n",totaltime);
	fclose(stdin);
	return 0;
}
