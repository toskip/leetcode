/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n==0 ||n==1) return n;
        map<double,int> xielv;
        int result = 0;
        int xielv0 = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(points[i].x!=points[j].x)
                {
                    double temp = (double)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                    xielv[temp]++;
                    result = max(result,xielv[temp]);
                }
                else
                {
                    xielv0++;
                    result = max(result,xielv0);
                }
            }
        }
        result = sqrt(result*2)+1;
        return result;
    }
};
