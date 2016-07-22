#include<iostream>
#include<cstdio>
#include<time.h> 
using namespace std;
int a[1010][1010];
int b[1010][1010];
int main()
{
	freopen("input.txt","r",stdin);
	clock_t start,finish;
	start = clock();
	double totaltime;
	int m,n;
	int i,j,p,q,ans,temp = 0;
	scanf("%d,",&m);
	scanf("%d,",&n);
	for (i = 1;i <= m;i++)
	for (j = 1;j <= n;j++) scanf("%d,",&a[i][j]);
	for (i = 1;i <= m;i++)
	for (j = 1;j <= n;j++)
	{
		temp = 0;
		for (p = 1;p <= i;p++)
		for (q = 1;q <= j;q++) temp = temp + a[p][q];
		b[i][j] = temp;
	}
	ans = a[1][1];
	for (i = 1;i <= m;i++)
	for (j = 1;j <= n;j++)
	for (p = i;p <= m;p++)
	for (q = j;q <= n;q++)
	{
		temp = b[p][q] - b[p][j - 1] - b[i - 1][q] + b[i - 1][j - 1];
		if (temp > ans) ans = temp;
	}
	printf("%d\n",ans);
	finish = clock();
	totaltime = finish - start;
	printf("%lf\n",totaltime);
	fclose(stdin);
	return 0;
}
