// hdu-1753-小数加.cpp : 定义控制台应用程序的入口点。
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
int ar[401];
int ad[401];
int br[401];
int bd[401];
int resr[401];
int resd[401];
int len1,len2,a_idr,a_idd,b_idr,b_idd;
int id1,id2;
char s1[401];
char s2[401];
int cd[401];
bool all_z;
void rev(int a[], int n)
{
	int i = 0;
	int j = n-1;
	while(i<=j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}
void add(int res[],int a[], int b[], int n1, int n2,int& len)
{
	int temp=0; int k = 0;
	int i = 0;
	for(;i<max(n1,n2);i++)
	{
		temp = a[i]+b[i]+k;
		k = temp/10;
		res[i]=temp%10;
	}
	while(k)
	{
		res[i++] = k%10;
		k/=10;
	}
	len = i;
}
void add_d(int res[],int a[], int b[], int n1, int n2,int& len)
{
	int i = n1-1;
	int j = n2-1;
	while(a[i]==0&&i>=0)
		i--;
	while(b[j]==0&&j>=0)
		j--;
	if(i<0&&j<0)
	{
		all_z = true;
		len = 0;
		return;
	}
	else if(i<0)
	{
		all_z = false;
		for(int k = 0;k<=j;k++)
		{
			res[k]=b[k];
		}
		len = j+1;
		return;
	}
	else if(j<0)
	{
		all_z = false;
		for(int k = 0;k<=i;k++)
			res[k]=a[k];
		len = i+1;
		return;
	}
	else
	{
		len = max(i,j)+1;
		int temp =0;int c= 0;
		for(int k = len-1;k>=0;k--)
		{
			temp = a[k]+b[k]+c;
			res[k]=temp%10;
			if(res[k])
				all_z = false;
			c = temp/10;
		}
		cd[0] = c;
		return;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",s1)!=EOF)
	{
		scanf("%s",s2);
		memset(ar,0,sizeof(ar));
		memset(ad,0,sizeof(ad));
		memset(br,0,sizeof(br));
		memset(bd,0,sizeof(bd));
		memset(resr,0,sizeof(resr));
		memset(resd,0,sizeof(resd));
		memset(cd,0,sizeof(cd));
		len1 = strlen(s1);
		len2 = strlen(s2);
		int ok = 0;
		a_idr = a_idd = 0;
		int x = -1;
		for(int i = 0;i<len1;i++)
		{
			if(s1[i]=='.')
			{
				x = i;
				break;
			}
		}
		if(x==-1)
			x=len1;
		int i = 0;
		while(s1[i]=='0'&&i<x)
			i++;
		for(;i<x;i++)
			ar[a_idr++]=s1[i]-'0';
		int j = len1-1;
		while(s1[j]=='0'&&j>x)
			j--;
		for(i=x+1;i<=j;i++)
			ad[a_idd++]=s1[i]-'0';
		rev(ar,a_idr);
		b_idr = b_idd = 0;
		ok = 0;
		x = -1;
		for(int i = 0;i<len2;i++)
		{
			if(s2[i]=='.')
			{
				x = i;
				break;
			}
		}
		if(x==-1)
			x=len2;
		i = 0;
		while(s2[i]=='0'&&i<x)
			i++;
		for(;i<x;i++)
			br[b_idr++]=s2[i]-'0';
		j = len2-1;
		while(s2[j]=='0'&&j>x)
			j--;
		for(i=x+1;i<=j;i++)
			bd[b_idd++]=s2[i]-'0';
		if(a_idr==0&&b_idr==0&&a_idd==0&&b_idd==0)
		{
			printf("0\n");
			continue;
		}
		rev(br,b_idr);
		add(resr,ar,br,a_idr,b_idr,len1);
		all_z = true;
		add_d(resd,ad,bd,a_idd,b_idd,len2);
		if(cd[0])
		{
			add(resr,resr,cd,len1,1,len1);
		}
		if(len1)
		{
			for(int i = len1-1;i>=0;i--)
				printf("%d",resr[i]);
		}
		if(all_z==false)
		{
			printf(".");
			for(int i = 0;i<len2;i++)
				printf("%d",resd[i]);
		}
		printf("\n");
	}
}

