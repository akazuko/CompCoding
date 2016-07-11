r = raw_input
M = 10**9 + 7
for t in range(int(r())):
	s = r()
	ss = s[0]
	c = s[0]

	for i in s:
		if i!=c:
			ss += i
			c = i
	n = len(ss)
	ans = 1
	if n==1:
		ans = 1
	else:
		ans = ( (4%M) * pow(3,n-2,M) )%M
	print "Case #%d: %d" %(t+1, ans%M)