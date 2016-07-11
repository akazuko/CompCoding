r=raw_input
def samesign(a, b):
	return a * b > 0
def bisect(func, low, high):
	for i in range(54):
		midpoint = (low + high) / 2.0
		if samesign(func(low), func(midpoint)):
			low = midpoint
		else:
			high = midpoint
	return midpoint

for t in range(int(r())):
	ans = 0.0
	m = int(r())
	coff = map(int, r().split())
	def f(x):
		val = -1*coff[0]*(x**m)
		for i in range(1,m+1):
			val += coff[i]*(x**(m-i))
		return val
	ans = bisect(f, 0, 2)
	ans = ans -1
	round(ans, 13)
	print 'Case #%d: %.12lf' %(t+1,ans)