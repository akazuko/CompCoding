# Enter your code here. Read input from STDIN. Print output to STDOUT
for T in range(int(raw_input())):
    N,M = map(int,raw_input().split())
    l = map(int,raw_input().split())
    max_so_far = 0
    max_ending_here = 0
    
    for i in range(N):
        l[i] = l[i]%M
    
    for k in l:
        max_ending_here += k
        if max_ending_here < 0:
            max_ending_here = 0
        if max_so_far < max_ending_here:
           max_so_far = max_ending_here
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
    print max_so_far