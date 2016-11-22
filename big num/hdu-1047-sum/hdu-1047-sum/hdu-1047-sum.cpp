// hdu-1047-sum.cpp : 定义控制台应用程序的入口点。
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
int res[205];
int a[205];
char s[101];
int len1,len2;
void add()
{
	int k = 0;
	int i = 0;
	for(;i<max(len1,len2);i++)
	{
		int temp = a[i]+res[i]+k;
		res[i]=temp%10;
		k = temp/10;
	}
	len1 = i;
	if(k)
	{
		res[i]=k;
		len1 = i+1;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(res,0,sizeof(res));
		memset(a,0,sizeof(a));
		len1 = 0;
		while(scanf("%s",s)!=EOF)
		{
			len2 = strlen(s);
			if(len2==1&&s[0]=='0')
			{
				if(len1==0)
					printf("0\n");
				else
				{
					for(int i = len1-1;i>=0;i--)
						printf("%d",res[i]);
					printf("\n");
				}
				if(t)
					printf("\n");
				break;
			}
			memset(a,0,sizeof(a));
			for(int i = 0;i<len2;i++)
			{
				a[i]=s[len2-1-i]-'0';
			}
			add();
		}
	}
}
