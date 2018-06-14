class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        version1 = version1.split('.')
        version2 = version2.split('.')
        len1 = len(version1)
        len2 = len(version2)
        version1 = [int(each) for each in version1]
        version2 = [int(each) for each in version2]
        if len1>len2:
            for i in range(len1-len2):
                version2.append(0)
        elif len1<len2:
            for i in range(len2-len1):
                version1.append(0)
        for i in range(max(len1,len2)):
            if version1[i]>version2[i]:
                return 1
            elif version1[i]<version2[i]:
                return -1
        return 0
        
