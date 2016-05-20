from collections import defaultdict
N=int(raw_input())
l=defaultdict(int)
for k in range(N):
    s=raw_input()
    t=defaultdict(int)
    for p in s:
        if t[p] == 0 :
            t[p]+=1
    for p in t:
        l[p]+=1
ans=0
for k in l:
    if l[k] >= N:
        ans+=1
print ans