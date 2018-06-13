class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        for(int i = 0;i<tokens.size();i++)
        {
            if(isdigit(tokens[i][tokens[i].size()-1]))
            {
                number.push(stoi(tokens[i]));
            }
            else
            {
                int a,b,c;
                b=number.top();
                number.pop();
                a = number.top();
                number.pop();
                if(tokens[i]=="+")
                {
                    c = a+b;
                }
                else if(tokens[i]=="-")
                {
                    c = a-b;
                }
                else if(tokens[i]=="*")
                {
                    c = a*b;
                }
                else if(tokens[i]=="/")
                {
                    c = a/b;
                }
                number.push(c);
            }
        }
        return number.top();
    }
};
