r=raw_input
for _ in range(int(r())):
	n,m =map(int,r().split())
	# print n,m
	if n==1 and m>2:
		print "No"
	elif m==1 and n>2:
		print "No"
	elif m==1 and n==1:
		print "No"
	elif m<=2 and n<=2:
		print "Yes"
	elif n%2==1 and m%2==1:
		print "No"
	else:
		print "Yes"