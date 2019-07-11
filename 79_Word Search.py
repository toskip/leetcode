class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.board = board
        self.word = word
        self.m = len(board)
        self.n = len(board[0])
        self.path = [[0 for j in range(self.n)] for i in range(self.m)]
        self.directions = [[0,1],[1,0],[0,-1],[-1,0]]
        pos = 0
        while pos<self.m*self.n:
            i = pos//self.n
            j = pos%self.n
            pos+=1
            if board[i][j]!=word[0]:
                continue
            if self.gao(i,j,0):
                return True
        return False
    def gao(self,i,j,count):
        #print("%d %d %d" %(i,j,count))
        if i<0 or j<0 or i>=self.m or j>=self.n or self.path[i][j]==1 or self.board[i][j]!=self.word[count]:
            return False
        self.path[i][j] = 1
        if count==len(self.word)-1:
            return True
        for d in self.directions:
            if self.gao(i+d[0],j+d[1],count+1):
                return True
        self.path[i][j] = 0
        return False
            
        
