#include<iostream>
#include<algorithm>
#include<memory.h>
#include<map>
using namespace std;
#define BIG 1000000009
map<int,int> cache;
int* a;
int* k;
int n,m,c;
int dfs(int m)
{
	int result=0;
	for(int i = 0;i<c;i++)
	{
		if(cache.find(m-k[i])==cache.end())
		{
			cache[m-k[i]] = dfs(m-k[i]);
		}
		result+=cache[m-k[i]]%BIG;
	}
	return result%BIG;
}
int main()
{
	cin>>n>>m>>c;
	a = new int[n];
	k = new int[c];
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		cache[i] = a[i];
	}
	for(int i = 0;i<c;i++)cin>>k[i];
	cout<<dfs(m)<<endl;
	return 0;
}
