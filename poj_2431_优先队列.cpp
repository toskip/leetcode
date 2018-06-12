//#include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > fuel(n,make_pair(0,0));
    priority_queue<int> q;
    for(int i = 0;i<n;i++)
    {
        cin>>fuel[i].first>>fuel[i].second;
    }
    int L,P;
    cin>>L>>P;
    sort(fuel.begin(),fuel.end(),cmp);
    fuel.push_back(make_pair(0,0));
    int pos = 0;
    int result = 0;
    for(int i = 0;i<n+1;i++)
    {
        P-=L-fuel[i].first-pos;
        pos=L-fuel[i].first;
        while(P<0)
        {
            if(q.empty())
            {
                cout<<-1<<endl;
                return 0;
            }
            P+=q.top();
            q.pop();
            result++;
        }
        q.push(fuel[i].second);
    }
    cout<<result<<endl;
    return 0;
}
