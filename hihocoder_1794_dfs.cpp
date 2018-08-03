// https://hihocoder.com/problemset/problem/1794
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int* a;
int* taken;
int n;
int result = 0;
int current = 0;
bool finish = false;
void dfs()
{
	if(finish) return;
	for(int i = 0;i<n-2;i++)
	{
		if(taken[i]) continue;
		for(int j = i+1;j<n-1;j++)
		{
			if(taken[j]) continue;
			for(int k = j+1;k<n;k++)
			{
				if(taken[k]) continue;
				if(a[i]+a[j]>a[k])
				{
					//cout<<a[i]<<a[j]<<a[k]<<endl;
					taken[i]=1;taken[j] =1;taken[k] = 1;
					current++;
					result = max(result,current);
					if(result==n/3)
					{
						finish = true;
						return;
					}
					dfs();
					if(finish) return;
					current--;
					taken[i]=0;taken[j] =0;taken[k] = 0;
				}
			}
		}
	}
}
int main()
{
	cin>>n;
	a = new int[n];
	taken = new int[n];
	memset(taken,0,sizeof(int)*n);
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	dfs();
	cout<<result<<endl;
	return 0;
}
