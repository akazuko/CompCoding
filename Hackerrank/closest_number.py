for _ in range(int(raw_input())):
    a,b,x=map(int,raw_input().split())
    z=float(a**b)
    print "%.0f" %(z-(z%x))
