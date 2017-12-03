/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//搞不懂这题的存在意义，懒的算了直接套上一题
bool myfunction (Interval i,Interval j) { return (i.start<j.start); }
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> result;
        //if(intervals.size()==0) return result;
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
