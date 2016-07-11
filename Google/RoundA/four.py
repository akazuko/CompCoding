r=raw_input
for t in range(int(r())):
	m, n = map(int, r().split())
	K = []
	L = []
	P = []
	C = []

	for block in xrange(n):
		k, l = map(int, r().split())
		power = map(int, r().split())
		cost = map(int, r().split())
		K.append(k)
		L.append(l)
		P.append(power)
		C.append(cost)

	