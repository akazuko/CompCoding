r=raw_input
f=10**9+7
for _ in range(int(r())):
	n,k=map(int,r().split())
	print ((k%f)*pow(k-1,n-1,f))%f