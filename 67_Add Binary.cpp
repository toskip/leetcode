class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        int bigger = max(lena,lenb);
        string result  = "";
        int i = 1;
        int jinwei = 0;
        int aa,bb;
        do
        {
            aa = (i<=lena)?(a[lena-i]-'0'):0;
            bb = (i<=lenb)?(b[lenb-i]-'0'):0;
            result = char('0'+(aa ^ bb ^jinwei))+result;
            jinwei = (aa+bb+jinwei)/2;
        }
        while(++i<=bigger);
        if(jinwei) result='1'+result;
        return result;
    }
};
