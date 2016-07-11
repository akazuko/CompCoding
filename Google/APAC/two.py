r=raw_input
for t in range(int(r())):
	n,k = map(int, r().split())
	# print r().split()
	a = map(int, r().split())
	b = map(int, r().split())
	c = map(int, r().split())
	d = map(int, r().split())

	ans = 0

	for p in range(n):
		for q in range(n):
			for rr in range(n):
				for s in range(n):
					if a[p]^b[q]^c[rr]^d[s] == k:
						ans+=1
	print "Case #%d: %d" %(t+1, ans)