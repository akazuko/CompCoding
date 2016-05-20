import itertools
def checkprime(m):
	# f = int(m**0.5)
	for i in range(2,100):
		if m%i==0:
			return i
	return -1
r=raw_input
for t in range(int(r())):
	print "Case #1:"
	n,j = map(int,r().split())
	count = 1	
	for k in itertools.product((0,1),repeat=n-2):
		val = '1' + ''.join(map(str,k)) + '1'
		if count>j:
			break
		ans = val + " "
		p=1
		for base in range(2,11):
			num = int(val,base)
			res = checkprime(num)
			if res==-1:
				p=0
				break
			else:
				ans+=str(res) + " "
		if p==1:
			print ans
			count+=1