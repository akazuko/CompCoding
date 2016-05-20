N, M = map(int , raw_input().split())
_sum=[0] * (N+1)
l = map(int, raw_input().split())
_sum[0] = 1
for i in range(M):
    for j in range(l[i],N+1):
        _sum[j] += _sum[j-l[i]]

print _sum[N]
