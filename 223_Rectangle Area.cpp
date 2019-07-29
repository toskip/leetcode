class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long I = max(A,E);
        long long J = max(B,F);
        long long K = min(C,G);
        long long L = min(D,H);
        //cout<<I<<" "<<J<<" "<<K<<" "<<L<<endl;
        if(L<J || K<I){
            return (C-A)*(D-B)+(G-E)*(H-F);
        }
        return ((long long)C-A)*((long long)D-B)+((long long)G-E)*((long long)H-F)-(K-I)*(L-J);
    }
};
