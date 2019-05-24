from fractions import Fraction
import math
class Solution:
    def getKB(self,point1,point2):
        try:
            k = Fraction(point2[1]-point1[1])/(point2[0]-point1[0])
            b = point1[1]-k*point1[0]
        except ZeroDivisionError as e:
            k = None
            b = point1[0]
        return k,b
    def maxPoints(self, points) -> int:
        points.sort(key=lambda x: x[0])
        #print(points)
        if len(points)<2:
            return len(points)
        d = {}
        for i in range(len(points)):
            for j in range(i+1,len(points)):
                kb = self.getKB(points[i],points[j])
                key = str(kb)
                keyi = str(points[i])
                keyj = str(points[j])
                if key not in d:
                    d[key] = {keyi,keyj}
                else:
                    d[key].add(keyi)
                    d[key].add(keyj)
        #print(d)
        count = {}
        for key in d:
            count[key] = 0
        result = 0
        for i in range(len(points)):
            keyi = str(points[i])
            for key in d:
                if keyi in d[key]:
                    count[key]+=1
                    if count[key]> result:
                        result = count[key]
        return result
