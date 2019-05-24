from fractions import Fraction
import math
class Solution:
    def getKB(self,point1,point2):
        try:
            k = (point2[1]-point1[1])/(point2[0]-point1[0])
            b = point1[1]-k*point1[0]
        except ZeroDivisionError as e:
            k = None
            b = point1[0]
        return k,b
    def maxPoints(self, points) -> int:
        points.sort(key=lambda x: x[0])
        points = list(map(lambda x: [Fraction(x[0]),Fraction(x[1])],points))
        #print(points)
        if len(points)<2:
            return len(points)
        d = {}
        for i in range(len(points)):
            for j in range(i+1,len(points)):
                k,b = self.getKB(points[i],points[j])
                key = str(k)+','+str(b)
                keyi = str(points[i][0])+','+str(points[i][1])
                keyj = str(points[j][0]) + ',' + str(points[j][1])
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
            keyi = str(points[i][0]) + ',' + str(points[i][1])
            for key in d:
                if keyi in d[key]:
                    count[key]+=1
                    if count[key]> result:
                        result = count[key]
        return result
