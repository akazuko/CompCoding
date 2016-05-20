for _ in range(int(raw_input())):
	A=raw_input()
	B=raw_input()
	y = 0
	d=dict()
	for i in A:
		d[i] = 1
	for i in B:
		if i in d:
			print "Yes"
			break
	else:
		print "No"