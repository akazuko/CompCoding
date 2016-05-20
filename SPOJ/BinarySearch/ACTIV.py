r=raw_input
while 1:
	n = int(r())

	if n==-1:
		break

	activ = []
	for i in range(n):
		activ.append(list(map(int,r().split())))
	activ.sort(key = lambda x : x[1])
	
	dp = [1 for X in range(n)]
	
	for i in range(1,n):
		cur_act = activ[i]
		start = 0
		end = i-1
		while start<=end:
			mid = start + (end-start)/2
			if cur_act[0] >= activ[mid][1]:
				start = mid+1
			else:
				end = mid-1
		
		dp[i] += dp[i-1]
		if end >=0:
			dp[i] += dp[end]
	print dp[n-1]