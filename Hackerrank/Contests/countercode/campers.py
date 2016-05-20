# Enter your code here. Read input from STDIN. Print output to STDOUT
N,K = map(int,raw_input().split())
l=map(int,raw_input().split())
l.sort()
first=1
ans=0
for k in l:
    temp=k-1-first+1
    if temp>0:
        ans+=temp/2
    first=k+2
    if first>N:
        first = N

temp=N-l[-1]-1+1
if temp>0:
    ans+=temp/2

print ans+len(l)