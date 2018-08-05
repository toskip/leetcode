class Solution {
public:
    string decodeAtIndex(string S, int K) {
        K--;
        int n  = S.size();
        unsigned long long length = 0;
        for(int i = 0;i<n;i++)
        {
            if(isdigit(S[i])) length*=S[i]-'0';
            else length++;
        }
        int i = n-1;
        string result;
        for(i =n-1;i>=0;i--)
        {
            //cout<<i<<' '<<S[i]<<' '<<length<<' '<<K<<endl;
            if(isdigit(S[i]))
            {
                length/=S[i]-'0';
                K%=length;
            }
            else
            {
                length--;
            }
            if(K==length)
            {
                result = S[i];
                break;
            }
        }
        return result;
    }
};
