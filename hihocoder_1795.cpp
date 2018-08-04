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
int dfs(int target)
{
	int result=0;
	for(int i = 0;i<c;i++)
	{
		if(!cache.count(target-k[i]))
		{
			cache[target-k[i]] = dfs(target-k[i]);
		}
		result+=cache[target-k[i]];
		result%=BIG;
	}
	return result;
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
	int result;
	if(m<=n)
    {
        result =a[m-1];
    }
    else  result = dfs(m-1);
    //for(int i = 0;i<m;i++)
    //cout<<i<<' '<<cache[i]<<endl;
	cout<<result<<endl;
	return 0;
}
