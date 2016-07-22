#include<iostream>
#include<cstdio>
#include<time.h>
using namespace std;
int a[1010][1010];
int main()
{
	freopen("input.txt","r",stdin);
	clock_t start,finish;
	start = clock();
	double totaltime;
	int m,n;
	int i,j,p,q,k,l,ans,temp = 0;
	scanf("%d,",&m);
	scanf("%d,",&n);
	for (i = 0;i < m;i++)
	for (j = 0;j < n;j++) scanf("%d,",&a[i][j]);
	ans = a[0][0];
	for (i = 0;i < m;i++)
	for (j = 0;j < n;j++)
	for (p = i;p < m;p++)
	for (q = j;q < n;q++)
	{
		temp = 0;
		for (k = i;k <= p;k++)
		for (l = j;l <= q;l++) temp = temp + a[k][l];
		if (temp > ans) ans = temp;
	}
	printf("%d\n",ans);
	finish = clock();
	totaltime = finish - start;
	printf("%lf\n",totaltime);
	fclose(stdin);
	return 0;
}
