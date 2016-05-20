r=raw_input
for t in xrange(int(r())):
	s=r()
	ans=s[0]
	for i in s[1:]:
		if i>=ans[0]:
			ans = i + ans
		else:
			ans = ans + i
	print "Case #%d: %s" %(t+1, ans)