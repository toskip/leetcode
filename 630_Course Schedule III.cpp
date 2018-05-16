//WA，摸索中
//https://www.cnblogs.com/grandyang/p/7126289.html
class Solution {
public:
    static bool cmp1(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
    static bool cmp2(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    static bool cmp3(vector<int> a,vector<int> b)
    {
        return a[2]<b[2];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        for(int i = 0;i<courses.size();i++)
        {
            courses[i].push_back(courses[i][1]-courses[i][0]);
        }
        sort(courses.begin(),courses.end(),cmp1);
        int time = 0;
        int count1 = 0;
        for(int i = 0;i<courses.size();i++)
        {
            if(time<=courses[i][2])
            {
                time+=courses[i][0];
                count1++;
            }
        }
        sort(courses.begin(),courses.end(),cmp2);
        time = 0;
        int count2 = 0;
        for(int i = 0;i<courses.size();i++)
        {
            if(time<=courses[i][2])
            {
                time+=courses[i][0];
                count2++;
            }
        }
        sort(courses.begin(),courses.end(),cmp3);
        time = 0;
        int count3 = 0;
        for(int i = 0;i<courses.size();i++)
        {
            if(time<=courses[i][2])
            {
                time+=courses[i][0];
                count3++;
            }
        }
        cout<<count1<<' '<<count2<<' '<<count3<<endl;
        return max(max(count1,count2),count3);
    }
};
