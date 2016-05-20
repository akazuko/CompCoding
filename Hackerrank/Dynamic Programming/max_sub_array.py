def max_sum_array(x):
    bestsofar=0
    bestnow=0
    startindexnow=-1
    startindexsofar=-1
    stopindexsofar=-1
    for i in range(len(x)):
        value=bestnow + x[i]
        if value > 0:
            if bestnow==0:
                startindexnow=0
            bestnow=value
        else:
            bestnow=0
        if bestnow>bestsofar:
            bestsofar=bestnow
            stopindexsofar=i
            startindexsofar=startindexnow
    if bestsofar==0:
        return max(x)
    return bestsofar

def max_sum(x):
    s=0
    neg=0
    for k in x:
        if k>0:
            s+=k
        else:
            neg+=1
    if neg==len(x):
        return max(x)
    return s

for T in range(int(raw_input())):
    N=int(raw_input())
    x=map(int,raw_input().split())
    print max_sum_array(x), max_sum(x)