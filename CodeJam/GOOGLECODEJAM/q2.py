r=raw_input
for t in range(int(r())):
	s=r()
	flips = 0
	s = s + " "
	prev = ' '
	for cur in s:
		if prev==' ' and cur=='-':
			prev = cur
		elif prev==' ' and cur=='+':
			prev = cur
		elif prev=='-' and cur=='-':
			prev = '-'
		elif prev=='-' and cur=='+':
			flips+=1
			prev = '+'
		elif prev=='-' and cur==' ':
			flips+=1
		elif prev=='+' and cur=='-':
			flips+=1
			prev = '-'
		elif prev=='+' and cur=='+':
			prev = cur
		elif prev=='+' and cur==' ':
			prev = cur
	print "Case #%d: %d" %(t+1,flips)
