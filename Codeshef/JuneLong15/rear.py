# Enter your code here. Read input from STDIN. Print output to STDOUT
N, M = map(int , raw_input().split())
l=[None] * (N+1)
l1 = [None] * M
def rec(n):
    if n==0:
        return 0
    elif n==1:
        if 1 in l1:
            return 1
        else:
            return 0
    elif n==2:
        if 1 in l1:
            if 2 in l1:
                return 2
            else:
                return 1
        if 2 in l1:
            return 1
        else:
            return 0
    elif l[n] is not None:
        return l[n]
    else:
        temp =0
        for i in l1:
            if n-i >= 0:
                temp = temp + rec(n-i)
                # print n,rec(n-i)
        l[n] = temp
        return l[n]

l1 = map(int, raw_input().split())
print rec(N)
print l