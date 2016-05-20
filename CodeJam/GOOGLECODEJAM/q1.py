r=raw_input
for t in range(int(r())):
	n=int(r())
	if n==0:
		print "Case #%d: INSOMNIA" %(t+1)
	else:
		d=[0]*10
		count = 0
		mu=2
		tnum = n;
		while True:
			temp = map(int,list(str(tnum)))
			for j in temp:
				if d[j] != 1 :
					d[j] = 1
					count += 1
			# print temp
			# print d
			if count == 10 :
				break
			tnum = mu*n
			mu+=1
		print "Case #%d: %d" %(t+1,tnum)
