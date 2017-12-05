#我想象不到没有split这题该咋做...
class Solution(object):
    def simplifyPath(self, path):
        path = path.split('/')
        result = []
        for i in range(len(path)):
            if(path[i]==".."): 
                if(len(result)): result.pop()
            elif(path[i]=="."or path[i]==""): pass
            else: result.append(path[i])
        result = "/"+'/'.join(result)
        return result;
        """
        :type path: str
        :rtype: str
        """
        
