//kmp算法，温故而知新
class Solution {
private:
    string haystack,needle;
    int* next;
public:
    void getNext()
    {
        next = new int[needle.size()+1];
        int i = 0;
        int j  = -1;
        next[0] = -1;
        while(i<needle.size())
        {
            if(j==-1 || needle[i]==needle[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }
    int kmp()
    {
        if(needle.size()==0) return 0;
        getNext();
        int i  = 0;
        int j  = 0;
        while(i<haystack.size())
        {
            if(j==-1 || haystack[i]==needle[j])
            {
                i++;
                j++;
                if(j==needle.size()) return i-needle.size();
            }
            else
            {
                j = next[j];
            }
        }
        return -1;
        
    }
    int strStr(string haystack, string needle) {
        
        this->haystack = haystack;
        this->needle = needle;
        return kmp();
    }
};
