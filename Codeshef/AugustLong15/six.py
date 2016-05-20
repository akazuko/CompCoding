N,K=map(int,raw_input().split())
A=map(int,raw_input().split())
ans=0
tot=N*(N+1)/2
last=0
for i in range(1,N):
	if (A[i-1]%A[i]==K):
		ans+=(i-last)*(N-i)
		last=i

print tot-ans