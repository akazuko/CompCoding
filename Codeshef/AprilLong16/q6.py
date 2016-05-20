r=raw_input
for _ in range(int(r())):
	A,k = map(int,r().split())
	s=r()
	n=len(s)
	if n==1:
		if k>=1:
			print 1
		else:
			if s=='a':
				print 1
			else:
				print 0
	elif n==2:
		if k>=2:
			print 1
		else:
			if k==1:
				if s[0]!='a' and s[1]!='a':
					print 0
				else:
					print 1
			elif k==0:
				if s=='aa':
					print 1
				else:
					print 0
	else:
		print 0