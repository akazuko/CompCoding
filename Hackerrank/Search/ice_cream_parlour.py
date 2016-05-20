# Enter your code here. Read input from STDIN. Print output to STDOUT
for T in range(int(raw_input())):
    M=int(raw_input())
    N=int(raw_input())
    l=map(int,raw_input().split())
    i=0
    for k in l:
        leftover=M-k
        if k>0:
            p=l[i+1:]
            if leftover in p:
                print i+1,p.index(leftover)+2+i
                break
        i+=1