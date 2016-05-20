import itertools
def checkprime(m):
	f = int(m**0.5)
	for i in range(2,f):
		if m%i==0:
			return i
	return -1
r=raw_input
for t in range(int(r())):
	print "Case #1:"
	n,j = map(int,r().split())
	k=list(itertools.product((0,1),repeat=n-2))
	l=map(lambda b : ''.join(map(str,b)),k)
	l=map(lambda b : '1' + b + '1', l)
	count = 1
	for i in l:
		if count > j :
			break
		ans = i + " "
		p=1
		for base in range(2,11):
			num = int(i,base)
			res = checkprime(num)
			if res==-1:
				p=0
				break
			else:
				ans+= str(res) + " "
		if p==1:
			print ans
			count+=1