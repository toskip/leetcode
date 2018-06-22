//有错误，待改正
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        map<int,int> digit;
        int maxdigit = 0;
        for(int i =0;i<n;i++)
        {
            int num = nums[i];
            int curdigit = 1;
            while(num/10)
            {
                num/=10;
                curdigit++;
            }
            digit[nums[i]] = curdigit;
            maxdigit = max(maxdigit,curdigit);
        }
        for(int count = 0;count<maxdigit;count++)
        {
            temp = nums;
            vector<int> counts(11,0);
            for(int i =0;i<n;i++)
            {
                //cout<<temp[i]<<' ';
            }
            //cout<<endl;
            for(int i =0;i<n;i++)
            {
                int cur = (temp[i]/(int)pow(10,max(0,digit[temp[i]]-maxdigit+count)))%10;
                counts[cur]++;
                //cout<<cur<<' ';
            }
            //cout<<endl;
            for(int i =9;i>=0;i--) counts[i]+=counts[i+1];
            for(int i =0;i<n;i++)
            {
                int cur = (temp[i]/(int)pow(10,max(0,digit[temp[i]]-maxdigit+count)))%10;
                nums[counts[cur+1]] = temp[i];
                counts[cur+1]++;
            }
            //for(int i = 0;i<n;i++) cout<<nums[i]<<' ';
            //cout<<endl;
        }
        string result = "";
        if(nums[0]==0) return "0";
        for(int i =0;i<n;i++)
        {
            result+=to_string(nums[i]);
        }
        return result;
    }
};
