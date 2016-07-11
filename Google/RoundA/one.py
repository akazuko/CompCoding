r = raw_input
for t in xrange(int(r())):
	ans = ""
	ssm = -1*float('inf')
	n = int(r())
	for i in xrange(n):
		name = r()
		# .replace(' ','')
		ss = len(set(name))
		if ss > ssm or (ss==ssm and name < ans): 
			ssm = ss
			ans = name

	print 'Case #%d: %s' %(t+1,ans)