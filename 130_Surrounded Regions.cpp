//很水没优化
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return;
        vector<bool> temp(n,0);
        vector<vector<bool> > status(m,temp);
        int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        stack<pair<int,int> > visit;
        for(int i =0;i<n;i++)
        {
            if(board[0][i]=='O') visit.push(make_pair(0,i));
            if(board[m-1][i]=='O') visit.push(make_pair(m-1,i));
        }
        for(int i =1;i<m-1;i++)
        {
            if(board[i][0]=='O') visit.push(make_pair(i,0));
            if(board[i][n-1]=='O') visit.push(make_pair(i,n-1));
        }
        while(!visit.empty())
        {
            pair<int,int> cur = visit.top();
            int i = cur.first;
            int j = cur.second;
            visit.pop();
            if(!status[i][j])
            {
                status[i][j] = 1;
                for(int d = 0;d<4;d++)
                {
                    int nexti = i+direction[d][0];
                    int nextj = j+direction[d][1];
                    if(nexti>=0 &&nexti<m && nextj>=0 && nextj<n &&board[nexti][nextj]=='O' &&!status[nexti][nextj]) visit.push(make_pair(nexti,nextj));
                }
            }
        }
        for(int i =1;i<m-1;i++)
        {
            for(int j = 1;j<n-1;j++)
            {
                if(!status[i][j] &&board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};
