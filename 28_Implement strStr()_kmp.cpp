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
    }
    int kmp(string haystack,string needle)
    {
        if(needle.size()==0) return 0;
        this->haystack = haystack;
        this->needle = needle;
        getNext();
        int i  = 0;
        int j  = 0;
        while(i<haystack.size())
        {
            while(j!=-1 && haystack[i]!=needle[j])
            {
                j = next[j];
            }
            ++j;
            ++i;
            if(j==needle.size()) return i-j;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};
