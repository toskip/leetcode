class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        int jinwei;
        do
        {
            ++digits[i];
            jinwei = digits[i]/10;
            digits[i]%=10;
        }
        while(i-- && jinwei);
        if(jinwei) digits.insert(digits.begin(),1);
        return digits;
    }
};
