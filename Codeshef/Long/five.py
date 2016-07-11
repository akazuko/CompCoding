R=raw_input
M = 10**9+7
for t in range(int(R())):
	n,k = map(int,R().split())
	l= map(int,R().split())
	val = 1
	summ = 0
	r = 0
	while r<=min(n,k):
		# print n,r,val
		if (k%2==0 and r%2==0) or (k%2==1 and r%2==1):
			summ = (summ%M + val%M)%M
		r+=1
		val = (val*(n-r+1))/r
	print summ%M