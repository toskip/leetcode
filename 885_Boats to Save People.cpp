bool cmp(int a, int b)
{
    return a>b;
}
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int result = n;
        sort(people.begin(),people.end(),cmp);
        //for(int i = 0;i<n;i++)cout<<people[i]<<' ';
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(people[i]+people[j]<=limit) j--;
            i++;
        }
        return j+1;
    }
};
