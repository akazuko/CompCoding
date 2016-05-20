r=raw_input
for t in range(int(r())):
	k,c,s = map(int,r().split())
	val = ' '.join(map(str,range(1,s+1))) 
	if k==s:
		print "Case #%d: %s" %(t+1,val)
	else:
		