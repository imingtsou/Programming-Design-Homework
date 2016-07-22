#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	freopen("input.txt","w",stdout);
	srand((unsigned)time(NULL));
	int m = 99,n = 80;
	int a[200][200];
	int i,j;
	for (i = 0;i < m;i++)
	for (j = 0;j < n;j++) a[i][j] = rand() % 201 - 100;
	printf("%d,\n%d,\n",m,n);
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++) printf("%d,",a[i][j]);
		printf("\n");
	}
	fclose(stdout);
	return 0;
} 
