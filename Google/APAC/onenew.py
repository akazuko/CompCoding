r = raw_input
M = 10**9 + 7
def daa()

for t in range(int(r())):
	s = r()
	ss = s[0]
	c = s[0]
	d = {}

	for i in s:
		if i!=c:
			ss += i
			c = i
	n = len(ss)

	print "Case #%d: %d" %(t+1, ans%M)