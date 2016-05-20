for T in range(int(raw_input())):
    N=int(raw_input())
    l=map(int,raw_input().split())
    s=[]
    su=0
    for k in l:
        su+=k
        s.append(su)
    ans=0
    i=0
    for k in s:
        left = 0
        right = 0
        if i == 0:
            left = 0
            right=s[-1]-s[i]
        elif i==(N-1):
            left = s[-1]-l[i]
            right=0
        else:
            left = s[i] - l[i]
            right = s[-1] - s[i]
        if left == right:
            ans=1
            break
        i+=1
    if ans == 1:
        print 'YES'
    else:
        print 'NO'