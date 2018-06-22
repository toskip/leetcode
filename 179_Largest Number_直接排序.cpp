bool cmp(string a, string b)
{
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nums2(n,"");
        for(int i = 0;i<nums.size();i++) nums2[i] = to_string(nums[i]);
        sort(nums2.begin(),nums2.end(),cmp);
        if(nums2[0]=="0") return "0";
        string result = "";
        for(int i =0;i<n;i++) result+=nums2[i];
        return result;
    }
};
