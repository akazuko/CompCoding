# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import *
T = int(raw_input())
for t in range(T):
    s=raw_input()
    le = len(s)
    ind = -1
    for k in range(le):
        if s[k] != s[le-1-k]:
            if ( k!=(le-2-k) and (k+1)!=(le-1-k) ):
                if s[k] == s[le-1-k-1]:
                    ind = le-1-k
                    break
                elif s[k+1] == s[le-1-k]:
                    ind = k
                    break
                else:
                    ind = k
                    break
            else:
                ind = k
                break
    print ind
       # c=defaultdict(int)
    # for k in s:
    #     c[k]+=1
    # pallin = 1
    # ch = ''
    # l=[]
    # for i in c:
    #     if c[i]%2 == 1:
    #         l.append(i)
    # temp = None
    # for k in l:
    #     i = s.index(k)
    #     if i != (le/2) :
    #         temp= i
    #         pallin = 0
    #         print temp, "y" , k
    #         break
    # if pallin == 0:
    #     print temp
    # else:
    #     print -1
