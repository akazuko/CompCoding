r=raw_input
n = int(r())
fr = map(int, r().split())
modd = 10**9+7 
q = int(r())

sol = [0] * n+1

for i in range(q):
	l = map(int, r().split())
	
	'''
	if(l[0]==1):
		fr[l[1]-1] = l[2]
	else:
		ans = 1
		b = l[1]
		for i in xrange(1,n+1,b):
			ans = ans*fr[i-1]
			# ans = ((ans%modd) * (fr[i-1]%modd))%modd
		print str(ans)[0], ans%modd
	'''

