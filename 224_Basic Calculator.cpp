class Solution {
public:
    int gao(int a,int b,char c){
        if(c=='+'){
            return a+b;
        }
        else {
            return a-b;
        }
    }
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        for(int i = 0;i<s.size();i++){
            //if(num.size()){
                //cout<<i<<" "<<s[i]<<" "<<num.top()<<endl;
                //cout<<op.size()<<endl;
            //}
            if(s[i]==' '){
                continue;
            }
            else if(s[i]>='0' && s[i]<='9'){
                int b = s[i]-'0';
                while(i+1<s.size()&&s[i+1]>='0'&&s[i+1]<='9'){
                    i++;
                    b = b*10+(s[i]-'0');
                }
                //cout<<i<<" "<<b<<endl;
                num.push(b);
            }
            else if(s[i]=='+' || s[i]=='-'||s[i]=='('){
                //cout<<i<<" "<<s[i]<<endl;
                op.push(s[i]);
                //cout<<s[i]<<endl;
                continue;
            }
            else if(s[i]==')'){
                while(op.top()!='('){
                    int b = num.top();
                    num.pop();
                    int a = num.top();
                    num.pop();
                    char c = op.top();
                    op.pop();
                    b = gao(a,b,c);
                    //cout<<i<<" "<<b<<endl;
                    num.push(b);
                }
                op.pop();
            }                
            if(!op.empty() && op.top()!='('){
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                char c = op.top();
                op.pop();
                b = gao(a,b,c);
                num.push(b);
                //cout<<i<<" "<<b<<endl;
                //op.pop();
            }
        }
        return num.top();
    }
};
