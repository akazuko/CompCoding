# Enter your code here. Read input from STDIN. Print output to STDOUT
def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x

for i in range(int(raw_input())):
    A,B,C = map(int, raw_input().split())
    temp=C-A
    if temp>=B:
        print '1/1'
    elif(temp<B and temp >0):
        if C>B:
            area = (B-C+A)*(A-C+B)
            area = 2*A*B - area
        else:
            area = C**2 - (C-A)**2
        k=gcd(area,2*A*B)
        p1=(2*A*B)/k
        p2=(area)/k
        print str(p2)+'/'+str(p1)
    elif temp<=0:
        if B>C:
            area = C**2
        else:
            area = C**2 - (C-B)**2
        k=gcd(area,2*A*B)
        p1=(2*A*B)/k
        p2=(area)/k
        print str(p2)+'/'+str(p1)