r=raw_input
for t in range(int(r())):
	n,q = map(int, r().split())
	data = map(int, r().split())
	csum  = [0] * n
	csum[0] = data[0]

	for i in range(1,n):
		csum[i] = csum[i-1] + data[i]

	qar = list(data)
	for i in range(n):
		for j in range(i+1,n):
			start = i-1
			end = j
			if start<0:
				qar.append(csum[end])
			else:
				qar.append(csum[end] - csum[start])
	print "Case #%d:" %(t+1)
	qar.sort()
	# print qar
	csumq = [0] * len(qar)
	csumq[0] = qar[0]
	for i in range(1,len(qar)):
		csumq[i] = csumq[i-1] + qar[i]

	for query in range(q):
		L,R = map(int, r().split())
		L-=1
		R-=1
		if L-1<0:
			print csumq[R]
		else:
			print csumq[R] - csumq[L-1]
