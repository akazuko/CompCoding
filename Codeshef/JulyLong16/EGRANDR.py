r=raw_input
for t in xrange(int(r())):
	n = int(r())
	F = False
	C = False
	A = map(int, r().split())
	for i in A:
		if i == 2:
			F = True
		if i == 5:
			C = True
	if F==False and C==True and  sum(A)>= 4*n:
		print "Yes"
	else:
		print "No" 