// hdu-1063-指数.cpp : 定义控制台应用程序的入口点。
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
int n;
int res[200];
int temp[200];
int f[6];
int len1,len2;
char str[10];
char s[7];
void mul()
{
	memset(temp,0,sizeof(temp));
	for(int i = 0;i<len1;i++)
	{
		for(int j = 0;j<len2;j++)
		{
			temp[i+j]+=res[i]*f[j];
		}
	}
	for(int i = 0;i<=len1+len2-2;i++)
	{
		temp[i+1]+=temp[i]/10;
		temp[i]=temp[i]%10;
	}
	int m = len1+len2-1;
	while(temp[m])
	{
		temp[m+1]+=temp[m]/10;
		temp[m] = temp[m]%10;
		m++;
	}
	len1 = m;
	memset(res,0,sizeof(res));
	memcpy(res,temp,sizeof(res));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",s)!=EOF)
	{
		memset(res,0,sizeof(res));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		int id=0;
		int l = 0;
		int have = 0;
		int all_z = 0;
		for(int i = 0;i<6;i++)
		{
			if(s[i]=='.')
			{
				id = i;
				have = 1;
			}
			else
			{
				f[l]=s[i]-'0';
				if(f[l]!=0)
					all_z = 1;
				l++;
			}
		}
		id = (5-id)*n;
		if(have==0)
			id=0;
		len1=len2 = l;
		for(int i = 0;i<len1;i++)
			res[len1-1-i]=f[i];
		for(int i = 0;i<len1;i++)
			f[i]=res[i];
		if(all_z==0)
		{
			printf("0\n");
			continue;
		}
		for(int i = 2;i<=n;i++)
			mul();
		if(id==0&&have==0)
		{
			int i = len1-1;
			while(res[i]==0)
				i--;
			for(;i>=0;i--)
				printf("%d",res[i]);
		}
		else if(id==0&&have==1)
		{
			int i = len1-1;
			while(res[i]==0)
				i--;
			for(;i>=0;i--)
				printf("%d",res[i]);
			printf(".");
		}
		else
		{
			int ok = 0;
			int e = 0;
			while(res[e]==0&&e<id)
				e++;
			for(int i = len1-1;i>=e;i--)
			{
				if(i+1==id)
				{
					printf(".");
					ok = 1;
				}
				if(res[i]==0&&ok==0)
					continue;
				else if(res[i]!=0&&ok==0)
					ok = 1;
				printf("%d",res[i]);
			}
		}
		printf("\n");
	}
}

