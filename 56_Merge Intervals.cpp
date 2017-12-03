/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//题不难，主要学习了一下自定义sort的方法
//vector的erase巨慢无比，改掉之后从103ms提升到12ms，轻易别用
bool myfunction (Interval i,Interval j) { return (i.start<j.start); }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size()==0) return result;
        sort(intervals.begin(),intervals.end(),myfunction);
        int i=1;
        int n  = intervals.size();
        Interval current=intervals[0];
        while(i<n)
        {
            if(current.end>=intervals[i].start)
            {
                current.end = max(current.end,intervals[i].end);
            }
            else
            {
                result.push_back(current);
                current = intervals[i];
            }
            i++;
        }
        result.push_back(current);
        return result;
    }
};
