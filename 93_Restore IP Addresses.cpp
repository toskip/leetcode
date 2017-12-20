class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> result;
        string stri,strj,strk,strl;
        int numi,numj,numk,numl;
        for(int i = 1;i<=3 &&i<n;i++)
        {
            stri = s.substr(0,i);
            if(stri[0]=='0' &&i!=1) continue;
            numi = atoi(stri.c_str());
            if(numi>=256) continue;
            for(int j = 1;j<=3&&i+j<n;j++)
            {
                strj = s.substr(i,j);
                if(strj[0]=='0' &&j!=1) continue;
                numj = atoi(strj.c_str());
                if(numj>=256) continue;
                for(int k =1;k<=3&&i+j+k<n;k++)
                {
                    strk = s.substr(i+j,k);
                    if(strk[0]=='0' &&k!=1) continue;
                    numk = atoi(strk.c_str());
                    if(numk>=256) continue;
                    strl = s.substr(i+j+k,n-i-j-k);
                    if(strl.size()>=4) continue;
                    if(strl[0]=='0' &&n-i-j-k!=1) continue;
                    numl = atoi(strl.c_str());
                    if(numl>=256) continue;
                    result.push_back(stri+'.'+strj+'.'+strk+'.'+strl);
                }
            }
        }
        return result;
    }
};
