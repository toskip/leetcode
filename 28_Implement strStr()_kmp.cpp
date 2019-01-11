class Solution {
public:
    string haystack;
    string needle;
    int* next;
    void getNext()
    {
        next= new int[needle.size()+1];
        next[0] = -1;
        int i= 0;
        while(i<needle.size())
        {
            //abdabdabab
            int j = next[i];
            while(j!=-1 && needle[i]!=needle[j])
            {
                j = next[j];
            }
            next[++i] = j+1;
        }
        for(int i = 0;i<=needle.size();i++)
        {
            cout<<next[i]<<' ';
        }
        cout<<endl;
    }
    int kmp(string haystack,string needle)
    {
        this->haystack = haystack;
        this->needle = needle;
        getNext();
        int i  = 0;
        int j  = 1;
        while(i<haystack.size())
        {
            
            while(next[j]!=-1 && needle[j]!=needle[next[j]])
            {
                j = next[j];
            }
            next[i] = j;
        }
        return i-needle.size();
    }
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};
