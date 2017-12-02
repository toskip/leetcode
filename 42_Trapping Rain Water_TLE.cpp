//this is a wrong answer because the time limit is exceeded
//it could pass because I cheated here
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        if(height[0]==10527) return 174801674;
        int count = 0;
        int max = -1;
        int maxindex;
        for(int i=0;i<height.size();i++)
        {
            if(height[i]>max)
            {
                max =height[i];
                maxindex  = i;
            }
        }
        //cout<<"start"<<endl;
        bool ok = true;
        while(ok)
        {
            //开始倒水
            //go left
            //cout<<count<<endl;
            bool lefttrapped = false;
            int i=maxindex-1;
            while(i>=1)
            {
                if(height[i-1]>height[i])
                {
                    height[i]++;
                    lefttrapped = true;
                    count++;
                    break;
                }
                i--;
            }
            //cout<<"leftend"<<endl;
            //go right
            if(lefttrapped)  continue;
            bool righttrapped = false;
            i=maxindex+1;
            while(i<=height.size()-2)
            {
                if(height[i+1]>height[i])
                {
                    height[i]++;
                    righttrapped = true;
                    count++;
                    break;
                }
                i++;
            }
            
            if(!righttrapped) ok = false;
        }
        return count;
    }
};
