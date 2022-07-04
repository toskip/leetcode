# https://i0.hdslb.com/bfs/article/1140e4af8f2224dc822adf31570d908832f496b7.jpg@870w_686h_progressive.webp
import random
import math
loop = 1000000
ok = 0
radius = 1
pi = 3.1415927
for l in range(loop):
    result = []
    for i in range(4):
        x = random.uniform(-1,1)
        y = random.uniform(-1,1)
        while x*x+y*y>=1:
            x = random.uniform(-1,1)
            y = random.uniform(-1,1)
        ang = math.degrees(math.atan(abs(y)/abs(x)))
        if y>=0 and x>=0:
            pass
        elif y>=0 and x<0:
            ang = 180-ang
        elif y<0 and x<0:
            ang = 180+ang
        elif y<0 and x>=0:
            ang = 360-ang
        result.append(ang)
        #print('%.2f %.2f %.2f %.2f' % (x,y,x*x+y*y,ang))
    result.sort()
    #print(result)
    for i in range(4):
        flag = True
        for j in range(4):
            if result[j]> (result[i]+180)%360:
                flag = False
                break
        if flag:
            break
    if flag:
        ok+=1
            
print('loop=%d, ok=%d, rate=%.2f%%' %(loop,ok,(ok/loop)*100) )
