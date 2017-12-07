//dfs
bool haxi[200][200];
class Solution {
public:
    int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    bool found;
    string word;
    void dfs(int i,int j,int wordpos,vector<vector<char>>& board)
    {
        if(found) return;
        if(wordpos==word.size())
        {
            found = true;
            return;
        }
        int nexti,nextj;
        for(int d = 0;d<4;d++)
        {
            nexti = i+move[d][0];
            nextj = j+move[d][1];
            if(nexti>=0 &&nexti<m &&nextj>=0&&nextj<n &&board[nexti][nextj]==word[wordpos] && 
               !haxi[nexti][nextj])
            {
                haxi[nexti][nextj] = 1;
                dfs(nexti,nextj,wordpos+1,board);
                haxi[nexti][nextj] = 0;
                if(found) return;
            }
        } 

    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        memset(haxi,0,sizeof(haxi));
        found = false;
        m = board.size();
        n = board[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    haxi[i][j] = 1;
                    dfs(i,j,1,board);
                    haxi[i][j] = 0;
                    if(found) return true;
                }
            }
        }
        return false;
    }
};
