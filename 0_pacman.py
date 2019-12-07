r = 20
print('\n'.join([' '.join(['*' if (i-r)*(i-r)+(j-r)*(j-r)<r*r and (j<=r or abs((i-r)/(j-r))>0.5) and (j-r)*(j-r)+(i-r/2)*(i-r/2)>=(r/8)*(r/8) else ' ' for j in range(r*2)])for i in range(r*2)]))
