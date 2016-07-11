from Queue import Queue
r=raw_input

def gen(n, cur, final, N):
	if n==N:
		# print cur
		final.append(list(cur))
		return

	for i in range(3):
		cur.append(i)
		gen(n+1, cur, final, N)
		cur.pop()

for t in range(int(r())):
	N,X,K,A,B,C = map(int, r().split())
	l = []
	# d = {}
	ans = 0.0
	gen(0, [], l, N)
	for seq in l:
		val = X
		p = 1.0
		for i in seq:
			if i == 0:
				val = val & K
				p *= (A/100.0)
			elif i == 1:
				val = val | K
				p *= (B/100.0)
			elif i == 2:
				val = val ^ K
				p *= (C/100.0)
		ans = ans + float(val*p)
	print "Case #%d: %.10f" %(t+1, ans)