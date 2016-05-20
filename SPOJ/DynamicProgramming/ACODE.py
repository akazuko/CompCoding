r=raw_input
def encoding(num):
	# num = num.replace('0','')
	n = len(num)
	dp=[0]*(n+1)
	# dp[1] = 1
	dp[1] = 1
	for i in range(2,n+1):
		if int(num[i-1])<=26 and int(num[i-1])>0:
			dp[i] = dp[i-1]
		tm =int(num[i-2]+num[i-1])
		if tm>=10 and tm<=26:
			if i-2>0:
				dp[i] += dp[i-2]
			else:
				dp[i]+=dp[1]
		print num, dp[i]
	return dp[n]
while True:
	num = r()
	if num=='0':
		break
	print encoding(num)