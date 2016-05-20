from collections import defaultdict

l1=defaultdict(int)
l2=defaultdict(int)

A=raw_input()
B=raw_input()

for k in A:
    l1[k]+=1
for k in B:
    l2[k]+=1
ans=0
h=list(set(l1.keys()+l2.keys()))
for k in h:
    ans+=abs(l1[k]-l2[k])
print ans