# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from queue import Queue
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #qq = Queue(maxsize=0)
        qq = [[root]]
        #qq.put([root])
        result = []
        while len(qq)!=0:
            current = qq[0]
            qq = qq[1:]
            if current[-1]==p or current[-1]==q:
                result.append(current)
                if len(result)>=2:
                    #print('test')
                    break
            if current[-1].left:
                qq.append(current+[current[-1].left])
            if current[-1].right:
                qq.append(current+[current[-1].right])
        i = 0
        for i in range(min(len(result[0]),len(result[1]))):
            if result[0][i]!=result[1][i]:
                i-=1
                break
        return result[0][i]
