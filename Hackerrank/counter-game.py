# Enter your code here. Read input from STDIN. Print output to STDOUT
from math import log
for T in range(int(raw_input())):
    N = long(raw_input())
    move = 0
    while(N>1):
        k=log(N,2)
        p=int(k)
        if (k-p) != 0:
            N = N - 2**p
            move+=1
        else:
            move+=p
            break
        
        
    if move%2 == 0:
        print 'Richard'
    else:
        print 'Louise'