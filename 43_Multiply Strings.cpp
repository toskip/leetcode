/*
图片解释
https://drscdn.500px.org/photo/130178585/m%3D2048/300d71f784f679d5e70fadda8ad7d68f
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" ||num2=="0") return "0";
        vector<int> indices[220];
        string result = "";
        for(int i=0;i<num1.size();i++)
        {
            for(int j=0;j<num2.size();j++)
            {
                int current = (num2[j]-'0')*(num1[i]-'0');
                int first = current/10;
                int second = current%10;
                indices[i+j].push_back(first);
                indices[i+j+1].push_back(second);
            }
        }
        int jinwei = 0;
        for(int i=num1.size()+num2.size()-1;i>=0;i--)
        {
            int sum = 0;
            for(int j=0;j<indices[i].size();j++)
                sum+=indices[i][j];
            sum+=jinwei;
            result+=char(sum%10+'0');
            jinwei = sum/10;
        }
        reverse(result.begin(),result.end());
        if(result[0]=='0') result.erase(0,1);
        return result;
    }
};
