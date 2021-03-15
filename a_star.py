#未完成
from heapq import * 
class AStar:
    def __init__(self):
        self._map = [[0,0,0,0,0,0,0],[0,0,0,9,0,0,0],[0,1,0,9,0,2,0],[0,0,0,9,0,0,0],[0,0,0,0,0,0,0]]
        self._d = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]
        self._f = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]
        self._g = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]
        self._h = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]
        self._d1 = [[1,0],[0,1],[-1,0],[0,-1]] #右下左上
        self._d2 = [[1,0],[0,1],[-1,0],[0,-1],[1,1],[-1,1],[-1,-1],[1,-1]] #右下左下左上右上
        self._start = [2,1]
        self._target= [2,5]
        self._open_list = []
        self._close_list = []
        self._open_list.append(self._start)
    def run(self):
        while len(self._open_list)!=0:
            # find the smallest one
            current = heappop(self._open_list)
            self._close_list.append(current)
            for d in self._d1:
                nex = [current[0]+d[0],current[1]+d[1]]
                if nex[0]>=0 and nex[0]<5 and nex[1]>=0 and nex[1]<7 and self._map[nex[0]][nex[1]]!=9 and nex not in self._close_list:
                    if nex not in self._open_list:
                        heappush(self._open_list,nex)
                        self._g[nex[0]][nex[1]] = self._g[current[0]][current[1]]+1
                        self._h[nex[0]][nex[1]] = self._distance(nex,self._target)
                        self._d[nex[0]][nex[1]] = str(d)
                    else:
                        if self._g[current[0]][current[1]]+1<self._g[nex[0]][nex[1]]:
                            self._g[nex[0]][nex[1]] = self._g[current[0]][current[1]]+1
                            self._d[nex[0]][nex[1]] = str(d)
                    self._f[nex[0]][nex[1]] = self._g[nex[0]][nex[1]]+self._h[nex[0]][nex[1]]
            print('\n'.join(' '.join(['%2d' % i for i in row]) for row in self._map))
            print('')
            print('\n'.join(' '.join(['%2d' % i for i in row]) for row in self._f))
            print('')
            print('\n'.join(' '.join([str(i) for i in row]) for row in self._d))
            print(self._open_list)
            print(self._close_list)
        
            

    def _distance(self,a,b):
        return abs(a[0]-b[0])+abs(a[1]-b[1])
    def __repr__(self):
        return '\n'.join(' '.join(['%2d' % i for i in row]) for row in self._map)

if __name__=='__main__':
    a_star = AStar()
    print(a_star)
    a_star.run()
