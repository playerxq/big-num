// hdu-1042-n!.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int res[maxn];
int n,len;
void mul(int k)
{
	int m = 0;
	int temp = 0;
	for(int i = 0;i<len;i++)
	{
		temp=res[i]*k+m;
		res[i]=temp%10;
		m = temp/10;
	}
	while(m)
	{
		res[len++]=m%10;
		m/=10;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(res,0,sizeof(res));
		res[0]=1;
		len = 1;
		for(int i = 1;i<=n;i++)
		{
			mul(i);
		}
		for(int i = len-1;i>=0;i--)
			printf("%d",res[i]);
		printf("\n");
	}
}

