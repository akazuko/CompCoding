# Enter your code here. Read input from STDIN. Print output to STDOUT
N,K=map(int,raw_input().split())
S=raw_input()
s=S[K-2:]
ans=''
s=s[::-1]
pos=1
m=0

for k in s:
    if int(k)==0:
        if pos==1:
            ans+='0'
            m=m^0
        else:
            go=ans
            if pos > K:
                go=ans[pos-4:]
            if m ==1:
                ans+=1
                m=m^1
                ans.append(1)
            else:
                ans+=
                m=m^
                ans.append(0)
    else:
        if pos==1:
            ans+=
            m=m^
            ans.append(1)
        else:
            m=0
            go=ans
            if pos > K:
                go=ans[pos-4:]
            for h in go:
                m=m^h
            if m ==1:
                ans+=
                m=m^
                ans.append(0)
            else:
                ans+=
                m=m^
                ans.append(1)
    pos+=1
z=''
ans.reverse()
for k in ans:
    z+=str(k)
print z[1:]
          