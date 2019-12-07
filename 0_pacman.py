import sys
r = 20
k = 0.5
inc = 0.025
while True:
    sys.stdout.write('\n'.join([' '.join(['*' if (i-r)*(i-r)+(j-r)*(j-r)<r*r and (j<=r or abs((i-r)/(j-r))>k) and (j-r)*(j-r)+(i-r/2)*(i-r/2)>=(r/8)*(r/8) else ' ' for j in range(r*2)])for i in range(r*2)]))
    k+=inc
    inc = -inc if k>=2 or k<=0.2 else inc
