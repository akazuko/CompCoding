N=int(raw_input())
l=[]
for k in range(N):
    l.append(int(raw_input()))
s=[1]*N

for i in range(N):
    if i==0:
        if l[i]>l[i+1]:
            s[i]+=1
    elif i==N-1:
        if l[i]>l[i-1]:
            s[i]=s[i-1]+1

    else:
        if l[i]>l[i-1] and l[i]>=l[i+1]:
            s[i]=s[i-1]+1
        elif l[i]>l[i-1] and l[i]<l[i+1]:
            s[i]=s[i-1]+1
        elif l[i]<l[i-1] and l[i]>l[i+1]:
            s[i]=s[i]+1
            if s[i]==s[i-1]:
                j=i
                while(j>=1 and l[j-1]>l[j] and s[j-1]==s[j]):
                    s[j-1]+=1
                    j-=1
        elif l[i]==l[i-1] and l[i]>l[i+1]:
            s[i]=s[i]+1

print sum(s)