r=raw_input
def solve(p,size,k):
	if k==0:
		return -1
	if k<0:
		return -1
	dp = [float('inf') for _ in range(k+1)]
	for w in range(1,k+1):
		for itemIdx in range(1,size+1):
			if p[itemIdx-1][1]==w:
				dp[w] = min(p[itemIdx-1][0], dp[w])
			elif p[itemIdx-1][1] < w:
				dp[w] = min(dp[w-p[itemIdx-1][1]] + p[itemIdx-1][0], dp[w])
			else:
				break
	if dp[w]==float('inf'):
		return -1
	else:
		return dp[w]

for t in range(int(r())):
	n,k=map(int,r().split())
	l=map(int,r().split())
	p=[]
	size = 0
	for i in range(1,n+1):
		if l[i-1]!=-1:
			p.append([l[i-1],i])
			size+=1
	print solve(p,size,k)