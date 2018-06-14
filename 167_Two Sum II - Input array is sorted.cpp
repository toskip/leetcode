class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> hash;
        int n = numbers.size();
        for(int i = 0;i<n;i++)
        {
            hash[numbers[i]] = i+1;
        }
        for(int i = 0;i<n;i++)
        {
            if(hash[target-numbers[i]])
            {
                vector<int> result(2,0);
                result[0] = min(i+1,hash[target-numbers[i]]);
                result[1] = max(i+1,hash[target-numbers[i]]);
                return result;
            }
        }
    }
};
